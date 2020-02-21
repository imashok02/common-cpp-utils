/************************************
 *
 * Copyright (c) 2015 Playzio Pvt. Ltd.
 *
 * http://www.playzio.net
 *
 **************************************/

#include "./UiUtil.h"  // NOLINT

#include "./SoundUtils.hpp"

namespace modules {

Text* UiUtil::addText(Node* parent, string label, Vec2 position, int label_size,
                      string label_font, Color4B label_color) {
  auto text_ = ui::Text::create(label, label_font, label_size);
  text_->setTextColor(label_color);
  text_->setPosition(position);

  parent->addChild(text_);
  return text_;
}

Scale9Sprite* UiUtil::addBgNode(Node* parent, string image, Size bg_size) {
  auto bg_ = ui::Scale9Sprite::create(image);
  bg_->setContentSize(bg_size);
  bg_->setPosition(Vec2(bg_size.width / 2, bg_size.height / 2));

  parent->addChild(bg_);
  return bg_;
}

Sprite* UiUtil::addBanner(Node* parent, string image, Vec2 position,
                          string label, Point label_offset, int label_size,
                          string label_font, Color4B label_color) {
  auto banner_ = Sprite::createWithSpriteFrameName(image);
  banner_->setPosition(position);
  auto banner_size = banner_->getContentSize();
  auto label_position = Vec2(label_offset.x * banner_size.width,
                             label_offset.y * banner_size.height);
  addText(banner_, label, label_position, label_size, label_font, label_color);

  parent->addChild(banner_);
  return banner_;
}

ui::ImageView* UiUtil::addImageView(Node* parent, string image, Vec2 position) {
  ui::ImageView* imgView =
      ui::ImageView::create(image, ui::Widget::TextureResType::PLIST);
  imgView->setPosition(position);
  parent->addChild(imgView);
  return imgView;
}

CommonLayout* UiUtil::addCommonLayout(Node* parent, Size size,
                                      ui::Layout::Type type) {
  CommonLayout* cmnLayout = CommonLayout::create();
  cmnLayout->setLayoutType(type);
  cmnLayout->setContentSize(size);
  parent->addChild(cmnLayout);

  return cmnLayout;
}
}  // namespace modules
