/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef _ACTIVEMQ_CORE_ACTIVEMQPRODUCER_H_
#define _ACTIVEMQ_CORE_ACTIVEMQPRODUCER_H_

#include <cms/MessageProducer.h>
#include <cms/Message.h>
#include <cms/Destination.h>
#include <cms/DeliveryMode.h>

#include <activemq/core/ActiveMQSessionResource.h>
#include <activemq/connector/ProducerInfo.h>

namespace activemq{
namespace core{

    class ActiveMQSession;

    class ActiveMQProducer : public cms::MessageProducer,
                             public ActiveMQSessionResource
    {
    private:

        // Disable sending timestamps
        bool disableTimestamps;

        // The default delivery Mode of this Producer
        int defaultDeliveryMode;

        // The default priority Level to send at
        int defaultPriority;

        // The default time to live value for messages in milliseconds
        long long defaultTimeToLive;

        // Session that this producer sends to.
        ActiveMQSession* session;

        // This Producers protocal specific info object
        connector::ProducerInfo* producerInfo;

        // Boolean that indicates if the consumer has been closed
        bool closed;

    public:

        /**
         * Constructor
         */
        ActiveMQProducer( connector::ProducerInfo* producerInfo,
                          ActiveMQSession* session );

        virtual ~ActiveMQProducer();

        /**
         * Closes the Consumer.  This will return all allocated resources
         * and purge any outstanding messages.  This method will block if
         * there is a call to receive in progress, or a dispatch to a
         * MessageListener in place
         * @throws CMSException
         */
        virtual void close() throw ( cms::CMSException );

        /**
         * Sends the message to the default producer destination.
         * @param a Message Object Pointer
         * @throws CMSException
         */
        virtual void send( cms::Message* message ) throw ( cms::CMSException );

        /**
         * Sends the message to the default producer destination, but does
         * not take ownership of the message, caller must still destroy it.
         * @param message - a Message Object Pointer
         * @param deliverMode The delivery mode to be used.
         * @param priority The priority for this message.
         * @param timeToLive The time to live value for this message in
         * milliseconds.
         * @throws CMSException
         */
        virtual void send( cms::Message* message, int deliveryMode, int priority,
            long long timeToLive) throw ( cms::CMSException );

        /**
         * Sends the message to the designated destination.
         * @param a Message Object Pointer
         * @throws CMSException
         */
        virtual void send( const cms::Destination* destination,
                           cms::Message* message ) throw ( cms::CMSException );

        /**
         * Sends the message to the designated destination, but does
         * not take ownership of the message, caller must still destroy it.
         * @param destination - a Message Object Pointer
         * @param message - a Message Object Pointer
         * @param deliverMode The delivery mode to be used.
         * @param priority The priority for this message.
         * @param timeToLive The time to live value for this message in
         * milliseconds.
         * @throws CMSException
         */
        virtual void send( const cms::Destination* destination,
            cms::Message* message, int deliveryMode, int priority,
            long long timeToLive) throw ( cms::CMSException );

        /**
         * Sets the delivery mode for this Producer
         * @param The DeliveryMode
         */
        virtual void setDeliveryMode( int mode ) {
            defaultDeliveryMode = mode;
        }

        /**
         * Gets the delivery mode for this Producer
         * @return The DeliveryMode
         */
        virtual int getDeliveryMode() const {
            return defaultDeliveryMode;
        }

        /**
         * Sets if Message Ids are disbled for this Producer
         * @param boolean indicating enable / disable (true / false)
         */
        virtual void setDisableMessageId( bool value ) {
            if( producerInfo != NULL ){
                producerInfo->setDisableMessageId( value );
            }
        }

        /**
         * Sets if Message Ids are disbled for this Producer
         * @param boolean indicating enable / disable (true / false)
         */
        virtual bool getDisableMessageId() const {
            if( this->producerInfo != NULL ) {
                return this->producerInfo->isDisableMessageId();
            }

            return false;
        }

        /**
         * Sets if Message Time Stamps are disbled for this Producer
         * @param boolean indicating enable / disable (true / false)
         */
        virtual void setDisableMessageTimeStamp( bool value ) {
            disableTimestamps = value;
        }

        /**
         * Sets if Message Time Stamps are disbled for this Producer
         * @param boolean indicating enable / disable (true / false)
         */
        virtual bool getDisableMessageTimeStamp() const {
            return disableTimestamps;
        }

        /**
         * Sets the Priority that this Producers sends messages at
         * @param int value for Priority level
         */
        virtual void setPriority( int priority ) {
            defaultPriority = priority;
        }

        /**
         * Gets the Priority level that this producer sends messages at
         * @return int based priority level
         */
        virtual int getPriority() const {
            return defaultPriority;
        }

        /**
         * Sets the Time to Live that this Producers sends messages with
         * @param time The new default time to live value in milliseconds.
         */
        virtual void setTimeToLive( long long time ) {
            defaultTimeToLive = time;
        }

        /**
         * Gets the Time to Live that this producer sends messages with
         * @return The default time to live value in milliseconds.
         */
        virtual long long getTimeToLive() const {
            return defaultTimeToLive;
        }

    public:  // ActiveMQSessionResource

        /**
         * Retrieve the Connector resource that is associated with
         * this Session resource.
         * @return pointer to a Connector Resource, can be NULL
         */
        virtual connector::ConnectorResource* getConnectorResource(void) {
            return producerInfo;
        }

    public:

        /**
         * Retrives this object ProducerInfo pointer
         * @return ProducerInfo pointer
         */
        virtual connector::ProducerInfo* getProducerInfo(void){
            return producerInfo;
        }

   };

}}

#endif /*_ACTIVEMQ_CORE_ACTIVEMQPRODUCER_H_*/
