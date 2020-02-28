#ifndef _CLASSES_COMMONPOPUP_H_
#define _CLASSES_COMMONPOPUP_H_

#include "UiUtil.h"
#include "CommonLayout.h"

namespace views {
  class CommonPopup : public LayerColor {
    public:
      static CommonPopup* createPopup(Size popup_size);
      virtual bool init();
      void build();
      void setPopupTitle(string titleText, Color3B color);
      void setBgImage(string img);
      void closePopup();
      CREATE_FUNC(CommonPopup);
      CommonLayout* mainLayout;
      CommonLayout* titleLayout;
      CommonLayout* contentLayout;
      CommonLayout* buttonsLayout;
    private:
      void addMainLayout();
      void swallowTouches();
      void addTitleLayout();
      void addContentLayout();
      void addButtonsLayout();
      void setPopupSize(Size popup_size);
      ui::Text* titleNode;
      Size popupSize;
      Size viewSize;
  };
}

#endif // _CLASSES_COMMONPOPUP_H_
