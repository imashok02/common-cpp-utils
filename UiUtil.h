/************************************
 *
 * Copyright (c) 2015 Playzio Pvt. Ltd.
 *
 * http://www.playzio.net
 *
 **************************************/

#ifndef CLASSES_UIUTIL_H_
#define CLASSES_UIUTIL_H_

#include <cocos2d.h>
#include <ui/CocosGUI.h>

#include <string>

#include "./CommonLayout.h"
#include "./Config.h"
#include "./CustomButton.h"

using cocos2d::Color3B;
using cocos2d::Color4B;
using cocos2d::Node;
using cocos2d::Point;
using cocos2d::Sprite;
using cocos2d::Vec2;
using cocos2d::ui::Button;
using cocos2d::ui::Layout;
using cocos2d::ui::Scale9Sprite;
using cocos2d::ui::Text;
using cocos2d::ui::Widget;
using std::string;
using views::CustomButton;

namespace modules {

class UiUtil {
 public:
  template <class T>
  static CustomButton<T>* addButton(
      Node* parent, string image, string disabled_image = "",
      T* callback_object = nullptr,
      void (T::*callback_function)(void) = nullptr, Vec2 position = Vec2(0, 0),
      string label = "", int label_size = 12,
      string label_font = core::Config::FONT_FILE,
      Color3B label_color = Color3B::BLACK) {
    auto button_ =
        CustomButton<T>::createButton(callback_object, callback_function);
    button_->loadTextureNormal(image, Widget::TextureResType::PLIST);
    if (disabled_image != "") {
      button_->loadTextureDisabled(disabled_image,
                                   Widget::TextureResType::PLIST);
    }
    button_->setPosition(position);
    button_->setTitleText(label);
    button_->setTitleFontName(label_font);
    button_->setTitleFontSize(label_size);
    button_->setTitleColor(label_color);
    button_->setZoomScale(-0.1);

    parent->addChild(button_);
    return button_;
  }

  static Text* addText(Node* parent, string label, Vec2 position = Vec2(0, 0),
                       int label_size = 12,
                       string label_font = core::Config::FONT_FILE,
                       Color4B label_color = Color4B::BLACK);

  static Scale9Sprite* addBgNode(Node* parent, string image,
                                 cocos2d::Size bg_size);

  static Sprite* addBanner(Node* parent, string image,
                           Vec2 position = Vec2(0, 0), string label = "",
                           Point label_offset = Point(0.5f, 0.5f),
                           int label_size = 12,
                           string label_font = core::Config::FONT_FILE,
                           Color4B label_color = Color4B::BLACK);

  static ui::ImageView* addImageView(Node* parent, string image,
                                     Vec2 position = Vec2::ZERO);

  static CommonLayout* addCommonLayout(
      Node* parent, Size size = Size::ZERO,
      Layout::Type type = Layout::Type::HORIZONTAL);
};
}  // namespace modules

#endif  // CLASSES_UIUTIL_H_
