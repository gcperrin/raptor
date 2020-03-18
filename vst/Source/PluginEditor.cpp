
#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
VstAudioProcessorEditor::VstAudioProcessorEditor (VstAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    setSize (800, 600);

    slider.setRange (0, 10, 0);
    slider.setSliderStyle (Slider::LinearHorizontal);
    slider.setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider.setBounds (200, 448, 150, 24);

    slider.addListener (this);
    addAndMakeVisible (&slider);

}

VstAudioProcessorEditor::~VstAudioProcessorEditor()
{
}

//==============================================================================
void VstAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello asshat!", getLocalBounds(), Justification::centred, 1);

}

void VstAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    // slider.reset (new Slider ("new slider"));
    // addAndMakeVisible (slider.get());
    // slider->setRange (0, 10, 0);
    // slider->setSliderStyle (Slider::LinearHorizontal);
    // slider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);

    // slider->setBounds (200, 448, 150, 24);

    toggleButton.reset (new ToggleButton ("yung_money"));
    addAndMakeVisible (toggleButton.get());
    // toggleButton->addListener (this);

    toggleButton->setBounds (488, 448, 150, 24);


}

void VstAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    processor.inputGain = -10f;
}
