#ifndef TIMERCONTAINER_H
#define	TIMERCONTAINER_H

#include <QMap>
#include <QPair>
#include <QList>
#include <QTimer>
#include <QMutex>

class Actor;
typedef QList<Actor*> ActorList;

class TimerEntry : public QObject
{
    Q_OBJECT
public:
    TimerEntry(int);
    void IncludeActor(Actor* ac);
    void ExcludeActor(Actor* ac);
    bool Empty();
private:
    int m_timeout;
    ActorList m_ActorList;
    QMutex m_ListMutex;
    QTimer m_timer;

public slots:
    void ProceedList();
};

typedef QMap<int, TimerEntry*> TimerMap;

class TimerContainer
{
private:
    TimerContainer();
    TimerContainer(const TimerContainer& orig);
    const TimerContainer& operator=(const TimerContainer&);

    TimerMap m_TimeToTimerMap; // <timeout, <Timer, ListOfObjects> >
    QMap<Actor*, TimerMap::iterator > m_ActorToIteratorMap; // fast deleting purposes;
public:
    static TimerContainer& Instance();
    void LoadTimer(Actor*, int time);
    void UnloadTimer(Actor*);
};

#endif	/* TIMERCONTAINER_H */

