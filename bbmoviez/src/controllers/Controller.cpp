#include "Controller.hpp"
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/ListView>
#include <limits>
#include <bb/cascades/Application>
#include <bb/cascades/AbstractCover>

Controller::Controller(bb::cascades::QmlDocument* rootQML):
m_root(rootQML)
{
}


