/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

class newLookAndFeel : public LookAndFeel_V4
{
public:
    void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider& slider) override {

        float diam = jmin(width, height);
        float radius = diam / 2.f;
        float centreX = x + width / 2;
        float centreY = y + height / 2;
        float rx = centreX - radius;
        float ry = centreY - radius;
        float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle));

        Rectangle<float> rotaryArea(rx, ry, diam, diam);
        rotaryArea.reduce(1.f, 1.f);

        g.setColour(Colours::antiquewhite);
        g.fillEllipse(rotaryArea);

        g.setColour(Colours::black);

        Path rotTick;

        rotTick.addRectangle(-2.5f, -radius, 5.f, 0.33 * radius);

        g.fillPath(rotTick, AffineTransform::rotation(angle).translated(centreX, centreY));
        g.drawEllipse(rotaryArea, 1.f);
    }
};

//==============================================================================
/**
*/
class ArdynsDistortionAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    ArdynsDistortionAudioProcessorEditor (ArdynsDistortionAudioProcessor&);
    ~ArdynsDistortionAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ArdynsDistortionAudioProcessor& processor;

    ScopedPointer<Slider> driveKnob;
    ScopedPointer<Slider> rangeKnob;
    ScopedPointer<Slider> blendKnob;
    ScopedPointer<Slider> volumeKnob;

    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> driveAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> rangeAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> blendAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> volumeAttachment;

    newLookAndFeel nLAF;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ArdynsDistortionAudioProcessorEditor)
};
