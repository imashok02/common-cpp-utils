/************************************
 *
 * Copyright (c) 2015 Playzio Pvt. Ltd.
 *
 * http://www.playzio.net
 *
 **************************************/

#ifndef CLASSES_CUSTOMBUTTON_H_
#define CLASSES_CUSTOMBUTTON_H_

#include <cocos2d.h>
#include <ui/CocosGUI.h>

#include "./SoundUtils.hpp"

using cocos2d::ui::Button;
using cocos2d::ui::Widget;

namespace views {

template <class AnyClass>
class CustomButton : public Button {
 private:
  void (AnyClass::*function)(void);
  AnyClass* object;

 public:
  void setCallback(AnyClass* _object, void (AnyClass::*_function)(void)) {
    this->function = _function;
    this->object = _object;
  }
  CREATE_FUNC(CustomButton);
  static CustomButton* createButton(AnyClass* _object,
                                    void (AnyClass::*_function)(void)) {
    CustomButton* button_ = CustomButton::create();
    button_->setCallback(_object, _function);
    return button_;
  }
  virtual void onEnter() {
    Button::onEnter();
    this->addTouchEventListener(
        [this](Ref* pSender, Widget::TouchEventType type) {
          if (type == Widget::TouchEventType::ENDED) {
            SoundUtils::getInstance()->playEfxBtnTouched();
            if (object != nullptr && function != nullptr) {
              (*object.*function)();
            }
          }
        });
  }
};
}  // namespace views

#endif  // CLASSES_CUSTOMBUTTON_H_
