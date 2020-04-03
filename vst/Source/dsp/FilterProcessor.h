#pragma once

#include <JuceHeader.h>

template <typename Type>
class FilterProcessor
{
public:
    //==============================================================================
    FilterProcessor()
    {
      float initCutoff = 1000.0f;
      cutoff = &initCutoff;
    }

    void setCutoff(float nextCutoff)
    {
      cutoff = &nextCutoff;
    }

    //==============================================================================
    void prepare (const juce::dsp::ProcessSpec& spec)
    {
      auto coeff = FilterCoefs::makeFirstOrderHighPass (spec.sampleRate, 1000.0f);
      auto& procFilter = filter.template get<0>();
      procFilter.state = *coeff;
      /* *filter.template get<1>().state = coeff; */
      filter.prepare (spec);
    }

    //==============================================================================
    template <typename ProcessContext>
    void process (const ProcessContext& context) noexcept
    {
        filter.process (context);
    }

    //==============================================================================
    void reset() noexcept
    {
        filter.reset();
    }

private:
    //==============================================================================
    float *cutoff;

    using IIRFilter = dsp::IIR::Filter<Type>;
    using FilterCoefs = dsp::IIR::Coefficients<Type>;
    dsp::ProcessorChain<dsp::ProcessorDuplicator<IIRFilter, FilterCoefs>> filter;
};
