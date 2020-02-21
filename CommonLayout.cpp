/************************************
 *
 * Copyright (c) 2015 Playzio Pvt. Ltd.
 *
 * http://www.playzio.net
 *
 **************************************/

#include "./CommonLayout.h"  //NOLINT

USING_NS_CC;

bool CommonLayout::init() {
  if (!Layout::init()) {
    return false;
  }

  return true;
}

void CommonLayout::justifyChildren(JUSTIFY justify_type, ALIGN align_type) {
  Vector<Node*> children = this->getChildren();
  ssize_t num_childs = children.size();
  Size layout_size = this->getContentSize();
  Type layout_type = this->getLayoutType();

  Size remaining_space = layout_size - getChildrenSize();

  for (Node* child : children) {
    Widget* child_widget = static_cast<Widget*>(child);

    if (child_widget) {
      ui::Margin margin = ui::Margin();
      Size child_size = child_widget->getContentSize();

      if (layout_type == Type::HORIZONTAL) {
        margin.left = getJustifyFactor(justify_type, remaining_space.width,
                                       num_childs, children.getIndex(child));

        margin.top = (layout_size.height - child_size.height) *
                     getAlignFactor(align_type);
      } else if (layout_type == Type::VERTICAL) {
        margin.top = getJustifyFactor(justify_type, remaining_space.height,
                                      num_childs, children.getIndex(child));

        margin.left =
            (layout_size.width - child_size.width) * getAlignFactor(align_type);
      }

      child_widget->getLayoutParameter()->setMargin(margin);
    }
  }
}

float CommonLayout::getJustifyFactor(JUSTIFY justify_type,
                                     float remaining_space, ssize_t num_child,
                                     ssize_t child_index) {
  // must be converted to switch for more than 5 case checks
  if (justify_type == JUSTIFY::EVENLY) {
    return remaining_space / (num_child + 1);
  }

  if (justify_type == JUSTIFY::INSIDE) {
    if (child_index == 0) return 0.0;
    return remaining_space / (num_child - 1);
  }

  if (justify_type == JUSTIFY::OUTSIDE) {
    if (child_index == 0) {
      return remaining_space / 2;
    }
    return 0.0;
  }

  return 0.0;
}

float CommonLayout::getAlignFactor(ALIGN align_type) {
  // must be converted to switch for more than 5 case checks
  if (align_type == ALIGN::CENTER) {
    return 0.5;
  }

  if (align_type == ALIGN::END) {
    return 1.0;
  }

  return 0.0;
}

Size CommonLayout::getChildrenSize() {
  ui::Layout::Type layout_type = this->getLayoutType();
  float w = 0, h = 0;

  Vector<Node*> childs = this->getChildren();
  for (Node* child : childs) {
    Widget* child_widget = static_cast<Widget*>(child);
    if (child_widget) {
      Size child_size = child_widget->getContentSize();
      ui::Margin margin = child_widget->getLayoutParameter()->getMargin();

      if (layout_type == Type::HORIZONTAL) {
        w += child_size.width;
        float child_height = child_size.height;
        h = MAX(h, child_height);
      } else if (layout_type == Type::VERTICAL) {
        float child_width = child_size.width;
        w = MAX(w, child_width);
        h += child_size.height;
      }
    }
  }

  return Size(w, h);
}

void CommonLayout::setBgColor(Color3B color) {
  this->setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);
  this->setBackGroundColor(color);
}
