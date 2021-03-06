#include "context.h"
#include "application.h"

ContextPrivate::ContextPrivate(Context *parent):
    QObject(),q_ptr(parent)
{
   mApptype = T_None;
}

Context::Context(QObject *parent) :
    QObject(parent),
    d_ptr(new ContextPrivate(this))
{

}

void Context::sendBroadcast(AppType type,OMessage &msg)
{
 oklApp->sendBroadcast(type,msg);
}

void Context::sendCmdTo(AppType type,OMessage &msg)
{
 oklApp->sendCmdTo(type,msg);
}

bool Context::startApplication(AppType type,char **argv)
{
 Q_D(Context);
 d->mApptype = type;
 oklApp->startApplication(type,argv);
 return true;
}

bool Context::setWindowWallPaper(const QString &path)
{
    oklApp->setWindowWallPaper(path);
    return true;
}

void Context::callBack(){
  oklApp->callBackPressed();
}

AppType Context::getAppType(){
  Q_D(Context);
  return d->mApptype;
}
