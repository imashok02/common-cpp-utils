#ifndef _CLASSES_COMMONPOPUP_H_
#define _CLASSES_COMMONPOPUP_H_

#include "UiUtil.h"
#include "CommonLayout.h"

namespace views {
  class CommonPopup : public LayerColor {
    public:
      static CommonPopup* createPopup(Size popup_size);
      virtual bool init();
      virtual void onEnter();
      void setPopupTitle(string titleText);
      void closePopup();
      CREATE_FUNC(CommonPopup);
    private:
      void addMainLayout();
      void swallowTouches();
      void addTitleLayout();
      void addContentLayout();
      void addButtonsLayout();
      void setPopupSize(Size popup_size);
      CommonLayout* mainLayout;
      CommonLayout* titleLayout;
      CommonLayout* contentLayout;
      CommonLayout* buttonsLayout;
      ui::Text* titleNode;
      Size popupSize;
      Size viewSize;
  };
}

#endif // _CLASSES_COMMONPOPUP_H_