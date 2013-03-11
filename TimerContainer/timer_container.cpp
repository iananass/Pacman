#include "timer_container.h"

#include "actor.h"
#include <QTimer>
#include <QList>
#include <QDebug>

TimerEntry::TimerEntry(int timeout)
: m_timeout(timeout)
, m_ListMutex(QMutex::Recursive)
{
    m_timer.start(timeout);
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(ProceedList()));
}

void TimerEntry::ProceedList()
{
    QMutexLocker l(&m_ListMutex);
    for (ActorList::iterator it = m_ActorList.begin(), ie = m_ActorList.end();
            it != ie; ++it) {
        (*it)->MakeTurn();
    }
}

void TimerEntry::IncludeActor(Actor* ac)
{
    QMutexLocker l(&m_ListMutex);
    m_ActorList.push_back(ac);
}

void TimerEntry::ExcludeActor(Actor* ac)
{
    QMutexLocker l(&m_ListMutex);
    for (ActorList::iterator it = m_ActorList.begin(), ie = m_ActorList.end();
            it != ie;) {
        if ((*it) == ac)
            it = m_ActorList.erase(it);
        else
            ++it;
    }
}

bool TimerEntry::Empty()
{
    QMutexLocker l(&m_ListMutex);
    return m_ActorList.empty();
}

TimerContainer::TimerContainer()
{
}

TimerContainer::TimerContainer(const TimerContainer&)
{
}

const TimerContainer& TimerContainer::operator=(const TimerContainer&)
{
    return *this;
}

TimerContainer& TimerContainer::Instance()
{
    static TimerContainer tc;
    return tc;
}

void TimerContainer::LoadTimer(Actor* ac, int time)
{
    TimerMap::iterator it = m_TimeToTimerMap.find(time);
    if (it == m_TimeToTimerMap.end()) {
        it = m_TimeToTimerMap.insert(time, new TimerEntry(time));
    }
    m_ActorToIteratorMap.insert(ac, it);
    (*it)->IncludeActor(ac);
}

void TimerContainer::UnloadTimer(Actor* ac)
{
    QMap<Actor*, TimerMap::iterator >::iterator it =  m_ActorToIteratorMap.find(ac);
    if (it == m_ActorToIteratorMap.end())
        return;
    (**it)->ExcludeActor(ac);
    
    if ((**it)->Empty())
        m_TimeToTimerMap.erase(*it);
    m_ActorToIteratorMap.erase(it);
    qDebug() << "Unload timer for " << ac;
}

