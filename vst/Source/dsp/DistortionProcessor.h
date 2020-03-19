#pragma once

#include <JuceHeader.h>

template <typename Type>
class DistortionProcessor
{
public:
    DistortionProcessor()
    {
        //waveshaper.functionToUse = [] (Type x) { return jlimit (Type (-0.1), Type (0.1), x); };
        waveshaper.processor.functionToUse = [] (Type x)
                                             {
                                                 return std::tanh (x);
                                             };
    }

    void prepare (const juce::dsp::ProcessSpec& spec)
    {
        waveshaper.prepare (spec);
    }

    template <typename ProcessContext>
    void process (const ProcessContext& context) noexcept
    {
        waveshaper.process (context);
    }

    void reset() noexcept
    {
        waveshaper.reset();
    }

private:
    juce::dsp::ProcessorWrapper<juce::dsp::WaveShaper<Type>> waveshaper;
};
