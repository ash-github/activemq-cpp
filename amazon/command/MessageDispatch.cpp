/*
  Licensed to the Apache Software Foundation (ASF) under one
  or more contributor license agreements.  See the NOTICE file
  distributed with this work for additional information
  regarding copyright ownership.  The ASF licenses this file
  to you under the Apache License, Version 2.0 (the
  "License"); you may not use this file except in compliance
  with the License.  You may obtain a copy of the License at
  
  http://www.apache.org/licenses/LICENSE-2.0
  
  Unless required by applicable law or agreed to in writing,
  software distributed under the License is distributed on an
  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
  KIND, either express or implied.  See the License for the
  specific language governing permissions and limitations
  under the License.
*/

#include "command/MessageDispatch.h"

using namespace ActiveMQ::Command;

/*
 *
 *  Marshalling code for Open Wire Format for MessageDispatch
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Groovy scripts in the
 *         activemq-core module
 *
 */
bool
MessageDispatch::isMarshalAware() const
{
    return false;
}

MessageDispatch::MessageDispatch()
{
    redeliveryCounter_ = 0;
}

int
MessageDispatch::getCommandType() const
{
    return TYPE;
}

MessageDispatch::~MessageDispatch()
{
}

boost::shared_ptr<const ConsumerId> MessageDispatch::getConsumerId() const
{
    return consumerId_;
}

void MessageDispatch::setConsumerId(const boost::shared_ptr<ConsumerId>& consumerId)
{
    consumerId_ = consumerId;
}

boost::shared_ptr<const ActiveMQDestination> MessageDispatch::getDestination() const
{
    return destination_;
}

void MessageDispatch::setDestination(const boost::shared_ptr<ActiveMQDestination>& destination)
{
    destination_ = destination;
}

boost::shared_ptr<const Message> MessageDispatch::getMessage() const
{
    return message_;
}

void MessageDispatch::setMessage(const boost::shared_ptr<Message>& message)
{
    message_ = message;
}

int MessageDispatch::getRedeliveryCounter() const
{
    return redeliveryCounter_;
}

void MessageDispatch::setRedeliveryCounter(int redeliveryCounter)
{
    redeliveryCounter_ = redeliveryCounter;
}
