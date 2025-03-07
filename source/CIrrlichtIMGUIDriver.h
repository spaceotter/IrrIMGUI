/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2015-2016 Andre Netzeband based on example OpenGL driver for IMGUI from Omar Cornut
 *
 * The original OpenGL implementation where this driver is based on was implemented
 * by Omar Cornut as an example how to use the IMGUI with OpenGL.
 * You can find the IMGUI here: https://github.com/ocornut/imgui
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/**
 * @file       CIrrlichtIMGUIDriver.h
 * @author     Andre Netzeband
 * @brief      Contains a driver that uses Irrlicht primitive drawing functions to render the GUI.
 * @addtogroup IrrIMGUIPrivate
 */

#ifndef IRRIMGUI_SOURCE_CIRRLICHTIMGUIDRIVER_H_
#define IRRIMGUI_SOURCE_CIRRLICHTIMGUIDRIVER_H_

/**
 * @addtogroup IrrIMGUIPrivate
 * @{
 */

// module includes
#include <IrrIMGUI/IrrIMGUIConfig.h>
#include <IrrIMGUI/IrrIMGUI.h>
#include "IIMGUIDriver.h"
#include "private/CGUITexture.h"

namespace IrrIMGUI
{
namespace Private
{

/// @brief Contains driver classes for the IMGUI render system.
namespace Driver
{

  /// @brief A driver that uses Irrlicht primitive drawing functions for rendering.
  class CIrrlichtIMGUIDriver : public IrrIMGUI::Private::IIMGUIDriver
  {
    friend class IrrIMGUI::Private::IIMGUIDriver;
    public:
    private:
      /// @{
      /// @name Constructor and Destructor

      /// @brief The constructor.
      /// @param pDevice is a pointer to the Irrlicht Device.
      CIrrlichtIMGUIDriver(irr::IrrlichtDevice * const pDevice);

      /// @brief The Destructor
      ~CIrrlichtIMGUIDriver(void);

      /// @}

      /// @{
      /// @name Methods used for rendering.

      /// @brief Renders a full IMGUI draw list (called by the IMGUI system).
      /// @param pDrawData is a list of data to draw.
      virtual void drawGUIList(ImDrawData * pDrawData) override;

      /// @brief Renders a single command list.
      /// @param pCommandList is the list of commands to render.
      static void drawCommandList(ImDrawList * pCommandList);

      /// @}

      /// @{
      /// @name Image/Texture and Font related methods.

      /// @brief Creates a GUI texture object out of raw data.
      /// @param ColorFormat Is the format of the Color of every Pixel.
      /// @param pPixelData  Is a pointer to the pixel array.
      /// @param Width       Is the number of Pixels in X direction.
      /// @param Height      Is the number of Pixels in Y direction.
      /// @return Returns an GUI texture object.
      virtual IGUITexture *createTexture(EColorFormat ColorFormat, irr::u8 * pPixelData, irr::u32 Width, irr::u32 Height) override;

      /// @brief Creates a GUI texture object out of an Irrlicht image.
      /// @param pImage Is a pointer to an Irrlicht image object.
      /// @return Returns an GUI texture object.
      virtual IGUITexture *createTexture(irr::video::IImage * pImage) override;

      /// @brief Creates a GUI texture object out of an Irrlicht texture.
      /// @param pTexture Is a pointer to an Irrlicht texture object.
      /// @return Returns an GUI texture object.
      virtual IGUITexture *createTexture(irr::video::ITexture * pTexture) override;

      /// @brief Creates a GUI texture out of the currently loaded fonts.
      /// @return Returns an GUI texture object.
      virtual IGUITexture *createFontTexture(void) override;

      /// @brief Updates a GUI texture object with raw data.
      /// @param pGUITexture Is a pointer to the GUI texture object.
      /// @param ColorFormat Is the format of the Color of every Pixel.
      /// @param pPixelData  Is a pointer to the pixel array.
      /// @param Width       Is the number of Pixels in X direction.
      /// @param Height      Is the number of Pixels in Y direction.
      virtual void updateTexture(IGUITexture * pGUITexture, EColorFormat ColorFormat, irr::u8 * pPixelData, irr::u32 Width, irr::u32 Height) override;

      /// @brief Updates a GUI texture object with an Irrlicht image.
      /// @param pGUITexture Is a pointer to the GUI texture object.
      /// @param pImage      Is a pointer to an Irrlicht image object.
      virtual void updateTexture(IGUITexture * pGUITexture, irr::video::IImage * pImage) override;

      /// @brief Updates a GUI texture object with an Irrlicht texture.
      /// @param pGUITexture Is a pointer to the GUI texture object.
      /// @param pTexture    Is a pointer to an Irrlicht image object.
      virtual void updateTexture(IGUITexture * pGUITexture, irr::video::ITexture * pTexture) override;

      /// @brief Updates a GUI texture with the currently loaded fonts.
      /// @param pGUITexture Is a pointer to the GUI texture object.
      virtual void updateFontTexture(IGUITexture * pGUITexture) override;

      /**
       * @brief Deletes an texture from graphic memory.
       * @param pGUITexture Is a pointer to the texture to delete. Do not use it afterwards!
       */
      virtual void deleteTexture(IGUITexture * pGUITexture) override;

      /// @}

      /// @brief An pixel offset that is applied to every vertex.
      static irr::core::vector3df mOffset;

  };

}
}
}

/**
 * @}
 */


#endif /* IRRIMGUI_SOURCE_CIRRLICHTIMGUIDRIVER_H_ */
