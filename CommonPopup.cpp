#include "CommonPopup.h"
#include "Config.h"


namespace views {

  CommonPopup* CommonPopup::createPopup(Size popup_size) {
    CommonPopup* instance = CommonPopup::create();
    instance->setPopupSize(popup_size);
    return instance;
  }

  void CommonPopup::setPopupSize(Size popup_size) {
    popupSize = popup_size;
  }

  bool CommonPopup::init() {
    if (!LayerColor::init()) {
      return false;
    }
    return true;
  }

  void CommonPopup::setPopupTitle(string titleText) {
    titleNode->setString(titleText);
    titleLayout->justifyChildren(CommonLayout::JUSTIFY::EVENLY);
  }

  void CommonPopup::swallowTouches() {
    auto swallowTouchListener = cocos2d::EventListenerTouchOneByOne::create();
    swallowTouchListener->setSwallowTouches(true);
    swallowTouchListener->onTouchBegan = [](cocos2d::Touch* touch, cocos2d::Event* event) {
      return true;  // if you are consuming it
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(swallowTouchListener,
      this);
  }

  void CommonPopup::onEnter() {
    LayerColor::onEnter();
    setColor(Color3B::BLACK);
    setOpacity(160);
    viewSize = Director::getInstance()->getVisibleSize();
    addMainLayout();
    addTitleLayout();
    addContentLayout();
    addButtonsLayout();
    mainLayout->justifyChildren(CommonLayout::JUSTIFY::EVENLY);
    swallowTouches();
  }

  void CommonPopup::addMainLayout() {
    mainLayout = CommonLayout::create();
    mainLayout->setContentSize(popupSize);
    mainLayout->setBackGroundImage(core::Config::POPUP_BG_IMAGE, ui::Widget::TextureResType::PLIST);
    mainLayout->setBackGroundImageScale9Enabled(true);
    mainLayout->setAnchorPoint(Point(0.5f, 0.5f));
    mainLayout->setPosition(Vec2(viewSize.width / 2, viewSize.height / 2));
    mainLayout->setLayoutType(ui::LayoutType::VERTICAL);
    addChild(mainLayout);
  }

  void CommonPopup::addButtonsLayout() {
    buttonsLayout = CommonLayout::create();
    buttonsLayout->setContentSize(cocos2d::Size(popupSize.width, popupSize.height * 0.15));
    buttonsLayout->setAnchorPoint(Point(0.5f, 0.5f));
    buttonsLayout->setLayoutType(ui::LayoutType::HORIZONTAL);
    mainLayout->addChild(buttonsLayout);
  }

  void CommonPopup::addContentLayout() {
    contentLayout = CommonLayout::create();
    contentLayout->setContentSize(cocos2d::Size(popupSize.width * 0.9, popupSize.height * 0.75));
    contentLayout->setAnchorPoint(Point(0.5f, 0.5f));
    contentLayout->setLayoutType(ui::LayoutType::VERTICAL);
    mainLayout->addChild(contentLayout);
  }

  void CommonPopup::addTitleLayout() {
    titleLayout = CommonLayout::create();
    titleLayout->setContentSize(cocos2d::Size(popupSize.width, popupSize.height * 0.1));
    titleLayout->setAnchorPoint(Point(0.5f, 0.5f));
    titleLayout->setLayoutType(ui::LayoutType::HORIZONTAL);

    titleNode = ui::Text::create("", core::Config::FONT_FILE, 28);
    titleLayout->addChild(titleNode);
    mainLayout->addChild(titleLayout);
  }

  void CommonPopup::closePopup() {
    removeFromParent();
  }
}