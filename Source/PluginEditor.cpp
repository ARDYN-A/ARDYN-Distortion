/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ArdynsDistortionAudioProcessorEditor::ArdynsDistortionAudioProcessorEditor (ArdynsDistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    addAndMakeVisible(driveKnob = new Slider("Drive"));
    driveKnob->setSliderStyle(Slider::Rotary);
    driveKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
    driveKnob->setLookAndFeel(&nLAF);

    addAndMakeVisible(rangeKnob = new Slider("Range"));
    rangeKnob->setSliderStyle(Slider::Rotary);
    rangeKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
    rangeKnob->setLookAndFeel(&nLAF);

    addAndMakeVisible(blendKnob = new Slider("Blend"));
    blendKnob->setSliderStyle(Slider::Rotary);
    blendKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
    blendKnob->setLookAndFeel(&nLAF);

    addAndMakeVisible(volumeKnob = new Slider("Volume"));
    volumeKnob->setSliderStyle(Slider::Rotary);
    volumeKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
    volumeKnob->setLookAndFeel(&nLAF);

    driveAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "drive", *driveKnob);
    rangeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "range", *rangeKnob);
    blendAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "blend", *blendKnob);
    volumeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "volume", *volumeKnob);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 200);
}

ArdynsDistortionAudioProcessorEditor::~ArdynsDistortionAudioProcessorEditor()
{
}

//==============================================================================
void ArdynsDistortionAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::white);

    g.setColour(Colours::black);
    g.setFont(15.0f);

    Rectangle<int> leftArea = getLocalBounds();
    Rectangle<int> rightArea = leftArea.removeFromRight(leftArea.getWidth() / 2);
    Rectangle<int> d = leftArea.removeFromLeft(leftArea.getWidth() / 2);
    Rectangle<int> r = leftArea;
    Rectangle<int> b = rightArea.removeFromLeft(rightArea.getWidth() / 2);
    Rectangle<int> v = rightArea;

    g.drawText("Drive", d.removeFromBottom(50), Justification::centred, false);
    g.drawText("Range", r.removeFromBottom(50), Justification::centred, false);
    g.drawText("Dry/Wet", b.removeFromBottom(50), Justification::centred, false);
    g.drawText("Volume", v.removeFromBottom(50), Justification::centred, false);
}

void ArdynsDistortionAudioProcessorEditor::resized()
{
    int border = 10;
    Rectangle<int> leftArea = getLocalBounds();
    Rectangle<int> rightArea = leftArea.removeFromRight(leftArea.getWidth()/2);

    //The below code is not ideal but its the first thing I came up with that worked...

    driveKnob->setBounds(leftArea.removeFromLeft(leftArea.getWidth()/2));
    rangeKnob->setBounds(leftArea);
    blendKnob->setBounds(rightArea.removeFromLeft(rightArea.getWidth()/2));
    volumeKnob->setBounds(rightArea);

    driveKnob->setBounds(driveKnob->getBounds().reduced(border));
    rangeKnob->setBounds(rangeKnob->getBounds().reduced(border));
    blendKnob->setBounds(blendKnob->getBounds().reduced(border));
    volumeKnob->setBounds(volumeKnob->getBounds().reduced(border));
}
