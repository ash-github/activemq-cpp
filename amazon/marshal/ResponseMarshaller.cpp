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

#include "netinet/in.h"
#include "marshal/ResponseMarshaller.h"
#include "command/Response.h"
#include "boost/shared_ptr.hpp"

using namespace ActiveMQ::Marshalling;
using namespace ActiveMQ::Command;
using namespace ActiveMQ::IO;
using std::auto_ptr;
using boost::shared_ptr;

/*
 *  Marshalling code for Open Wire Format for Response
 *
 * NOTE!: This file is autogenerated - do not modify!
 *        if you need to make a change, please see the Groovy scripts in the
 *        activemq-core module
 */

ResponseMarshaller::ResponseMarshaller()
{
    // no-op
}

ResponseMarshaller::~ResponseMarshaller()
{
    // no-op
}

auto_ptr<IDataStructure> ResponseMarshaller::createCommand() 
{
    return auto_ptr<IDataStructure>(new Response());
}

char ResponseMarshaller::getDataStructureType() 
{
    return Response::TYPE;
}

/* 
 * Un-marshal an object instance from the data input stream
 */ 
void
ResponseMarshaller::unmarshal(ProtocolFormat& wireFormat, IDataStructure& o, BinaryReader& dataIn, BooleanStream& bs) 
{
    BaseCommandMarshaller::unmarshal(wireFormat, o, dataIn, bs);

    Response& info = (Response&) o;
    info.setCorrelationId( dataIn.readInt() );

}

/*
 * Write the booleans that this object uses to a BooleanStream
 */
size_t
ResponseMarshaller::marshal1(ProtocolFormat& wireFormat, const IDataStructure& o, BooleanStream& bs) {
    Response& info = (Response&) o;

    int rc = BaseCommandMarshaller::marshal1(wireFormat, info, bs);
    
    return rc + 4;
}

/* 
 * Write a object instance to data output stream
 */
void
ResponseMarshaller::marshal2(ProtocolFormat& wireFormat, const IDataStructure& o, BinaryWriter& dataOut, BooleanStream& bs) {
    // }

    BaseCommandMarshaller::marshal2(wireFormat, o, dataOut, bs);

    Response& info = (Response&) o;
    dataOut.writeInt(info.getCorrelationId());
}
