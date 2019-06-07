/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Images.h"

//==============================================================================
/**
*/
class Glasgowkeene_a2AudioProcessorEditor  : public AudioProcessorEditor, Slider::Listener
{
public:
    Glasgowkeene_a2AudioProcessorEditor (Glasgowkeene_a2AudioProcessor&, AudioProcessorValueTreeState&);
    ~Glasgowkeene_a2AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    
    Image backgroundImage;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    
    //create sliders
    Slider mixSlider;
    Slider bitSlider;
    
    //create labels for sliders
    Label mixLabel;
    Label bitLabel;

    //creating attachments to connect my sliders to the APVTS
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mixAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> bitAttachment;
   
    void sliderValueChanged (Slider* slider) override;
    
    AudioProcessorValueTreeState & valueTreeState;
    
    Glasgowkeene_a2AudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Glasgowkeene_a2AudioProcessorEditor)
};
