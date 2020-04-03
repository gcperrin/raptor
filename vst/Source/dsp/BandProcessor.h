#include <JuceHeader.h>

template <typename Type>
class Filter
{
public:
    //==============================================================================
    Filter()
    {
    }

    //==============================================================================
    void prepare (const juce::dsp::ProcessSpec& spec)
    {
      filter.state = FilterCoefs::makeFirstOrderHighPass (spec.sampleRate, 1000.0f);
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
    enum
    {
        filterIndex,
        preGainIndex,
        waveshaperIndex,
        postGainIndex
    };

    using Filter = juce::dsp::IIR::Filter<Type>;
    using FilterCoefs = juce::dsp::IIR::Coefficients<Type>;
    juce::dsp::ProcessorDuplicator<Filter, FilterCoefs> filter;
};
