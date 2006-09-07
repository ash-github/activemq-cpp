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

#ifndef JournalTopicAck_h_
#define JournalTopicAck_h_

#include <string>
#include <vector>
#include <exception>
#include <inttypes.h>
#include <boost/shared_ptr.hpp>

#include "command/AbstractCommand.h"    
#include "ActiveMQDestination.h"
#include "MessageId.h"
#include "TransactionId.h"

namespace ActiveMQ {
  namespace Command {

    /*
     *
     *  Marshalling code for Open Wire Format for JournalTopicAck
     *
     *
     *  NOTE!: This file is autogenerated - do not modify!
     *         if you need to make a change, please see the Groovy scripts in the
     *         activemq-core module
     *
     */
    class JournalTopicAck : public AbstractCommand
    {
      private:
        boost::shared_ptr<const ActiveMQDestination> destination_;
        boost::shared_ptr<const MessageId> messageId_;
        int64_t messageSequenceId_;
        std::string subscritionName_;
        std::string clientId_;
        boost::shared_ptr<const TransactionId> transactionId_;

      public:
        const static int TYPE = 50;
    
      public:
        JournalTopicAck();
        virtual ~JournalTopicAck();
    
        virtual bool isMarshalAware() const;
        virtual int getCommandType() const;

        virtual boost::shared_ptr<const ActiveMQDestination> getDestination() const;
        virtual void setDestination(const boost::shared_ptr<ActiveMQDestination>& destination);

        virtual boost::shared_ptr<const MessageId> getMessageId() const;
        virtual void setMessageId(const boost::shared_ptr<MessageId>& messageId);

        virtual int64_t getMessageSequenceId() const;
        virtual void setMessageSequenceId(int64_t messageSequenceId);

        virtual const std::string& getSubscritionName() const;
        virtual void setSubscritionName(const std::string& subscritionName);

        virtual const std::string& getClientId() const;
        virtual void setClientId(const std::string& clientId);

        virtual boost::shared_ptr<const TransactionId> getTransactionId() const;
        virtual void setTransactionId(const boost::shared_ptr<TransactionId>& transactionId);
    };
  }
}

#endif /*JournalTopicAck_h_*/
