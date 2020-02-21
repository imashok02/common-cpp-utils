/************************************
 *
 * Copyright (c) 2015 Playzio Pvt. Ltd.
 *
 * http://www.playzio.net
 *
 **************************************/

#ifndef CLASSES_COMMONLAYOUT_H_
#define CLASSES_COMMONLAYOUT_H_

#include <cocos2d.h>
#include <ui/CocosGUI.h>

USING_NS_CC;

class CommonLayout : public ui::Layout {
 public:
  // Align's children in layout direction
  enum class JUSTIFY {
    EVENLY,  // evenly spaceout the children
    INSIDE,  // spaceout between the children
    OUTSIDE  // divides remaining space at start & end of layout
  };

  // Align's children in layout opposite direction
  enum class ALIGN { CENTER, START, END };

  virtual bool init();

  // Should set the size of layout before using this method
  void justifyChildren(JUSTIFY, ALIGN align_type = ALIGN::CENTER);

  float getAlignFactor(ALIGN);

  float getJustifyFactor(JUSTIFY, float, ssize_t, ssize_t);

  Size getChildrenSize();

  void setBgColor(Color3B);

  CREATE_FUNC(CommonLayout);
};

#endif  // CLASSES_COMMONLAYOUT_H_
