#pragma once

#include <JuceHeader.h>
#include <iostream>

class CoreStyle : public LookAndFeel_V4
{
public:
    CoreStyle()
    {
      // set core colors
      borderColor = Colours::lightgrey;

      // set custom component colors
      bandOneColor = Colours::lightsalmon;
      bandTwoColor = Colours::cyan;
      bandThreeColor = Colours::blueviolet;
    }


    /* void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos, */
    /*                        const float rotaryStartAngle, const float rotaryEndAngle, Slider&) override */
    /* { */
    /*     auto radius = jmin (width / 2, height / 2) - 4.0f; */
    /*     auto centreX = x + width  * 0.5f; */
    /*     auto centreY = y + height * 0.5f; */
    /*     auto rx = centreX - radius; */
    /*     auto ry = centreY - radius; */
    /*     auto rw = radius * 2.0f; */
    /*     auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle); */

    /*     // fill */
    /*     g.setColour (Colours::orange); */
    /*     g.fillEllipse (rx, ry, rw, rw); */

    /*     // outline */
    /*     g.setColour (Colours::red); */
    /*     g.drawEllipse (rx, ry, rw, rw, 1.0f); */

    /*     Path p; */
    /*     auto ponterLength = radius * 0.33f; */
    /*     auto pointerThickness = 2.0f; */
    /*     p.addRectangle (-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength); */
    /*     p.applyTransform (AffineTransform::rotation (angle).translated (centreX, centreY)); */

    /*     // pointer */
    /*     g.setColour (Colours::yellow); */
    /*     g.fillPath (p); */
    /* } */

    void drawButtonBackground (Graphics& g, Button& button, const Colour& backgroundColour,
                               bool isMouseOverButton, bool isButtonDown) override
    {

      // fill
      Colour buttonBorder = borderColor;
      float borderSize = 2.0f;
      String buttonId = button.getComponentID();

      // TODO: Change to keyed hash
      if (buttonId == "b1")
      {
        buttonBorder = bandOneColor;
      }
      if (buttonId == "b2")
      {
        buttonBorder = bandTwoColor;
      }
      if (buttonId == "b3")
      {
        buttonBorder = bandThreeColor;
      }


      auto buttonArea = button.getLocalBounds();
      buttonArea.reduce(5, 5);
      g.setColour (Colours::black.withAlpha (0.5f));

      if (button.getToggleState() == true)
      {
        borderSize = 8.0f;
        g.setColour (Colours::lightgrey.withAlpha (0.5f));
      }


      g.fillRect (buttonArea);

      // border
      Path outline;
      outline.addRectangle(button.getLocalBounds());

      g.setColour(buttonBorder);
      g.strokePath(outline, PathStrokeType(borderSize));
    }

    /* void drawButtonText (Graphics& g, TextButton& button, bool, bool isButtonDown) override */
    /* { */
    /*     auto font = getTextButtonFont (button, button.getHeight()); */
    /*     g.setFont (font); */
    /*     g.setColour (button.findColour (button.getToggleState() ? TextButton::textColourOnId */
    /*                                                             : TextButton::textColourOffId) */
    /*                        .withMultipliedAlpha (button.isEnabled() ? 1.0f : 0.5f)); */

    /*     auto yIndent = jmin (4, button.proportionOfHeight (0.3f)); */
    /*     auto cornerSize = jmin (button.getHeight(), button.getWidth()) / 2; */

    /*     auto fontHeight = roundToInt (font.getHeight() * 0.6f); */
    /*     auto leftIndent  = jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnLeft()  ? 4 : 2)); */
    /*     auto rightIndent = jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnRight() ? 4 : 2)); */
    /*     auto textWidth = button.getWidth() - leftIndent - rightIndent; */

    /*     auto edge = 4; */
    /*     auto offset = isButtonDown ? edge / 2 : 0; */

    /*     if (textWidth > 0) */
    /*         g.drawFittedText (button.getButtonText(), */
    /*                           leftIndent + offset, yIndent + offset, textWidth, button.getHeight() - yIndent * 2 - edge, */
    /*                           Justification::centred, 2); */
    /* } */


private:
    Colour borderColor;
    Colour bandOneColor;
    Colour bandTwoColor;
    Colour bandThreeColor;
};
