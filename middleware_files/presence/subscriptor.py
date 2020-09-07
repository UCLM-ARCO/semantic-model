#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys, Ice, IceStorm
Ice.loadSlice('../SLICE/SemanticModel.ice', ['-I', '/usr/share/slice'])
import SemanticModel

class EventMonitorI (Events.EventMonitor):
    def report (self, message, curr):
        print message.type

class Subscriber (Ice.Application):
    def run (self, argv):
        self.shutdownOnInterrupt()
        # Proxy al TopicManager.
        prx = self.communicator().stringToProxy('Events/TopicManager:tcp -p 10000')
        topicManagerPrx = IceStorm.TopicManagerPrx.checkedCast(prx)
        # Creación del objeto remoto.
        oa = self.communicator().createObjectAdapterWithEndpoints('SubscriberOA', 'default')
        eventMonitorPrx = oa.addWithUUID(EventMonitorI())
        # Proxy al topic.
        try:
            topicPrx = topicManagerPrx.retrieve('alarms')
        except IceStorm.NoSuchTopic:
            topicPrx = topicManagerPrx.create('alarms')
        # Subscripción.
        topicPrx.subscribeAndGetPublisher(None, eventMonitorPrx)
        oa.activate()
        self.communicator().waitForShutdown()
        topicPrx.unsubscribe(eventMonitorPrx)
        return 0

Subscriber().main(sys.argv)
