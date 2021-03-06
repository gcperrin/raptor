#include "CoreProcessor.h"
#include "CoreEditor.h"
/* #include "dsp/DistortionProcessor.h" */
/* #include "dsp/GainProcessor.h" */
/* #include "dsp/FilterProcessor.h" */

#define ISDEV 1

CoreProcessor::CoreProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{

}

CoreProcessor::~CoreProcessor()
{
}

const String CoreProcessor::getName() const
{
    return JucePlugin_Name;
}

bool CoreProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool CoreProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool CoreProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double CoreProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int CoreProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int CoreProcessor::getCurrentProgram()
{
    return 0;
}

void CoreProcessor::setCurrentProgram (int index)
{
}

const String CoreProcessor::getProgramName (int index)
{
    return {};
}

void CoreProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void CoreProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
  dsp::ProcessSpec spec;
  spec.sampleRate = sampleRate;
  spec.maximumBlockSize = samplesPerBlock;
  spec.numChannels = getTotalNumInputChannels();

  auto& filterOne = fxChain.template get<filterIndex>();
  filterOne.prepare(spec);
  filterOne.setCutoff(100.0f);

  auto& filterTwo = fxChain2.template get<filterIndex>();
  filterTwo.prepare(spec);
  filterTwo.setCutoff(1000.0f);

  auto& filterThree = fxChain3.template get<filterIndex>();
  filterThree.prepare(spec);
  filterThree.setCutoff(10000.0f);

}

void CoreProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool CoreProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void CoreProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // clears no-input channels for errant data
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // Process audio block with chain
    auto block = juce::dsp::AudioBlock<float> (buffer);
    auto context = juce::dsp::ProcessContextReplacing<float> (block);
    auto context2 = juce::dsp::ProcessContextReplacing<float> (block);
    auto context3 = juce::dsp::ProcessContextReplacing<float> (block);

    // Audio input is independent to create the parallel processing chain
    fxChain.process (context);
    fxChain2.process (context2);
    fxChain3.process (context3);

}


//==============================================================================
bool CoreProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* CoreProcessor::createEditor()
{
    return new CoreEditor (*this);
}

//==============================================================================
void CoreProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void CoreProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CoreProcessor();
}

// All VST UI paramater values need to reside here for access from listeners in
// the appropraite plugin editor classes
void CoreProcessor::setGain(float level)
{
   auto& preGain = fxChain.template get<preGainIndex>();
   preGain.params->level = level;
}
