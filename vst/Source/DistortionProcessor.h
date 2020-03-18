#pragma once

#include <JuceHeader.h>

template <typename Type>
class Distortion
{
public:
    //==============================================================================
    Distortion()
    {
        auto& waveshaper = processorChain.template get<waveshaperIndex>();
        //waveshaper.functionToUse = [] (Type x) { return jlimit (Type (-0.1), Type (0.1), x); };

        waveshaper.functionToUse = [] (Type x)
                                   {
                                       return std::tanh (x);
                                   };

        auto& preGain = processorChain.template get<preGainIndex>();
        preGain.setGainDecibels (50.0f);

        auto& postGain = processorChain.template get<postGainIndex>();
        postGain.setGainDecibels (-10.0f);
    }

    //==============================================================================
    void prepare (const juce::dsp::ProcessSpec& spec)
    {
        // auto& filter = processorChain.template get<filterIndex>();
        // filter.state = FilterCoefs::makeFirstOrderHighPass (spec.sampleRate, 1000.0f);

        processorChain.prepare (spec);
    }

    //==============================================================================
    template <typename ProcessContext>
    void process (const ProcessContext& context) noexcept
    {
        processorChain.process (context);
    }

    //==============================================================================
    void reset() noexcept
    {
        processorChain.reset();
    }

private:
    //==============================================================================
    enum
    {
        // filterIndex,
        preGainIndex,
        waveshaperIndex,
        postGainIndex
    };

    using Filter = juce::dsp::IIR::Filter<Type>;
    using FilterCoefs = juce::dsp::IIR::Coefficients<Type>;

    juce::dsp::ProcessorChain<juce::dsp::Gain<Type>,
                              juce::dsp::WaveShaper<Type>,
                              juce::dsp::Gain<Type>> processorChain;
};
