/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "activemq/command/XATransactionId.hpp"

using namespace apache::activemq::command;

/*
 *
 *  Command and marshalling code for OpenWire format for XATransactionId
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Groovy scripts in the
 *         activemq-core module
 *
 */
XATransactionId::XATransactionId()
{
    this->formatId = 0 ;
    this->globalTransactionId = NULL ;
    this->branchQualifier = NULL ;
}

XATransactionId::~XATransactionId()
{
}

unsigned char XATransactionId::getDataStructureType()
{
    return XATransactionId::TYPE ; 
}

        
int XATransactionId::getFormatId()
{
    return formatId ;
}

void XATransactionId::setFormatId(int formatId)
{
    this->formatId = formatId ;
}

        
array<char> XATransactionId::getGlobalTransactionId()
{
    return globalTransactionId ;
}

void XATransactionId::setGlobalTransactionId(array<char> globalTransactionId)
{
    this->globalTransactionId = globalTransactionId ;
}

        
array<char> XATransactionId::getBranchQualifier()
{
    return branchQualifier ;
}

void XATransactionId::setBranchQualifier(array<char> branchQualifier)
{
    this->branchQualifier = branchQualifier ;
}

int XATransactionId::marshal(p<IMarshaller> marshaller, int mode, p<IOutputStream> ostream) throw (IOException)
{
    int size = 0 ;

    size += TransactionId::marshal(marshaller, mode, ostream) ; 
    size += marshaller->marshalInt(formatId, mode, ostream) ; 
    size += marshaller->marshalByteArray(globalTransactionId, mode, ostream) ; 
    size += marshaller->marshalByteArray(branchQualifier, mode, ostream) ; 
    return size ;
}

void XATransactionId::unmarshal(p<IMarshaller> marshaller, int mode, p<IInputStream> istream) throw (IOException)
{
    TransactionId::unmarshal(marshaller, mode, istream) ; 
    formatId = (marshaller->unmarshalInt(mode, istream)) ; 
    globalTransactionId = (marshaller->unmarshalByteArray(mode, istream)) ; 
    branchQualifier = (marshaller->unmarshalByteArray(mode, istream)) ; 
}
