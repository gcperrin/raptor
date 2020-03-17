/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class VstAudioProcessorEditor  : public AudioProcessorEditor

{
public:
    VstAudioProcessorEditor (VstAudioProcessor&);
    ~VstAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    VstAudioProcessor& processor;
    std::unique_ptr<Slider> slider;
    std::unique_ptr<ToggleButton> toggleButton;



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VstAudioProcessorEditor)
};
