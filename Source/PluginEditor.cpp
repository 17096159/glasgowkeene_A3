/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Glasgowkeene_a2AudioProcessorEditor::Glasgowkeene_a2AudioProcessorEditor (Glasgowkeene_a2AudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), processor (p), valueTreeState(vts)
{
   //create background
    setOpaque(true);
    //GUI size x + y
    setSize (400, 300);
    //setResizable(true, true);
    
    //ADD T-REX IMAGE:
    backgroundImage = ImageCache::getFromMemory(Images::tRexxerSmall_png, Images::tRexxerSmall_pngSize);
    
    //MIX SLIDER:
    //circular slider with vertical drag:
    mixSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    //0-100% range for wet/dry:
    mixSlider.setRange(0.0f, 1.0f);
    //"%" sign for mix level label:
    mixSlider.setTextValueSuffix(" % ");
    //label is below slider:
    mixSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, true, 50, 12);
    //label text:
    mixLabel.setText ("Dry / Wet", dontSendNotification);
    //set slider colour:
    mixSlider.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::black);
    //text box colour:
    mixSlider.setColour(Slider::ColourIds::textBoxTextColourId, Colours::white);
    mixSlider.addListener(this); //slider listener
    addAndMakeVisible(mixSlider); //smake slider visible
    addAndMakeVisible (mixLabel); //make text visible
    //attach the slider to the attachment that links our processor param of the same name with this slider:
    mixAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment (valueTreeState, "mix", mixSlider));

    //BIT SLIDER:
    //circular slider with vertical drag:
    bitSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    bitSlider.setRange(1.0f, 8.0f); //1-8 range for bit crushing
    bitSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, true, 40, 12); //label is below slider
    bitLabel.setText ("Bit Rate", dontSendNotification); //label text
    bitSlider.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::black); //slider colour = black
    bitSlider.setColour(Slider::ColourIds::textBoxTextColourId, Colours::white); //text box colour = white
    bitSlider.addListener(this); //slider listener
    addAndMakeVisible(bitSlider); //make slider visible
    addAndMakeVisible (bitLabel); //make text visible
    //attach the slider to the attachment that links our processor param of the same name with this slider:
    bitAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment (valueTreeState, "bitRate", bitSlider));
}

Glasgowkeene_a2AudioProcessorEditor::~Glasgowkeene_a2AudioProcessorEditor()
{
}

//==============================================================================
void Glasgowkeene_a2AudioProcessorEditor::paint (Graphics& g)
{
   // g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.fillAll (Colours::darkgrey); //background colour
    //make t-rex image the background:
    g.drawImage(backgroundImage, 0, 0, getWidth(), getHeight(), 0, 0, getWidth(), getHeight());
}

void Glasgowkeene_a2AudioProcessorEditor::resized()
{
    //Slider & label positioning:
    mixSlider.setBounds(190, getHeight()-170, 80, 80);
    mixLabel.setBounds(195, getHeight()-110, 80, 80);
    
    bitSlider.setBounds(280, getHeight()-170, 80, 80);
    bitLabel.setBounds(290, getHeight()-110, 80, 80);
}

void  Glasgowkeene_a2AudioProcessorEditor::sliderValueChanged(Slider *slider) {
    if (slider == &mixSlider)
    {
        // get the value on current slider, pass that value to our audio processor
        processor.mixLevel.setTargetValue(mixSlider.getValue());
    }
    
    if (slider == &bitSlider)
    {
        // get the value on current slider, pass that value to our audio processor
        processor.bitValue.setTargetValue(bitSlider.getValue());
    }
}
