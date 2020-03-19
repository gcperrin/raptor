
#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class VstAudioProcessorEditor  : public AudioProcessorEditor,
                                 private Slider::Listener
{
public:
    VstAudioProcessorEditor (VstAudioProcessor&);
    ~VstAudioProcessorEditor();

    void paint (Graphics&) override;
    void resized() override;

private:
    void sliderValueChanged (Slider* slider) override;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    VstAudioProcessor& processor;
    Slider slider;
    std::unique_ptr<ToggleButton> toggleButton;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VstAudioProcessorEditor)
};
