#pragma once

#include <JuceHeader.h>
#include "../CoreStyle.h"
#include "ControlContainer.h"

class BandSelectorContainer: public Component {
public:
    BandSelectorContainer()
    {
      bandOne.setComponentID("b1");
      bandOne.setLookAndFeel(&coreStyle);
      bandOne.setButtonText ("Band 1");
      bandOne.onClick = [this] { buttonClicked(1); };
      /* bandOne.setToggleState(true, NotificationType::dontSendNotification); */
      /* bandOne.setEnabled (true); // use with enablementChanged callback */

      bandTwo.setComponentID("b2");
      bandTwo.setLookAndFeel(&coreStyle);
      bandTwo.setButtonText ("Band 2");
      bandTwo.onClick = [this] { buttonClicked(2); };

      bandThree.setComponentID("b3");
      bandThree.setLookAndFeel(&coreStyle);
      bandThree.setButtonText("Band 3");
      bandThree.onClick = [this] { buttonClicked(3); };

      addAndMakeVisible(bandOne);
      addAndMakeVisible(bandTwo);
      addAndMakeVisible(bandThree);
    }

    void paint (Graphics& g) override
    {
        g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
        g.setColour (Colours::black);

        Rectangle<int> container = getLocalBounds();
        Rectangle<int> innerContainer = container.withSizeKeepingCentre(container.getWidth() - 2,
                                                                        container.getHeight() - 2);

        Path path;
        path.addRectangle (innerContainer);
        g.fillPath (path);
    }

    void resized() override
    {
        Grid grid;
        using Track = Grid::TrackInfo;

        grid.templateRows = { Track (1_fr) };
        grid.templateColumns = { Track (1_fr), Track (1_fr), Track (1_fr) };
        grid.items = { GridItem (bandOne), GridItem (bandTwo), GridItem (bandThree) };
        grid.performLayout (getLocalBounds());
    }

    void buttonClicked(int band)
    {

      switch (band)
      {
        case 1:
          bandOne.setToggleState(true, NotificationType::dontSendNotification);
          bandTwo.setToggleState(false, NotificationType::dontSendNotification);
          bandThree.setToggleState(false, NotificationType::dontSendNotification);
          break;
        case 2:

          bandOne.setToggleState(false, NotificationType::dontSendNotification);
          bandTwo.setToggleState(true, NotificationType::dontSendNotification);
          bandThree.setToggleState(false, NotificationType::dontSendNotification);
          break;
        case 3:
          bandOne.setToggleState(false, NotificationType::dontSendNotification);
          bandTwo.setToggleState(false, NotificationType::dontSendNotification);
          bandThree.setToggleState(true, NotificationType::dontSendNotification);
          break;
      }
      this->removeChildComponent(2);
    }


    Colour backgroundColour;

private:
    CoreStyle coreStyle;
    TextButton activeButton;
    TextButton bandOne;
    TextButton bandTwo;
    TextButton bandThree;
};
