#pragma once

#include <JuceHeader.h>

template <typename Type>
class GainProcessor
{
public:
    struct Parameters : dsp::ProcessorState
    {
        float level = 0.0f;
        using Ptr = ReferenceCountedObjectPtr<Parameters>;
    };

    GainProcessor()
    {
    }

    void prepare(const juce::dsp::ProcessSpec& spec)
    {
        gain.prepare (spec);
        gain.processor.setRampDurationSeconds(0.1);
    }

    template <typename ProcessContext>
    void process(const ProcessContext& context) noexcept
    {
        gain.processor.setGainDecibels (params->level);
        gain.process (context);
    }

    void reset() noexcept
    {
        gain.reset();
    }

    typename Parameters::Ptr params = new Parameters;

private:
    juce::dsp::ProcessorWrapper<juce::dsp::Gain<Type>> gain;
};
