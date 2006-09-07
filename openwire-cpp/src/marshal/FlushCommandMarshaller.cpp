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
#include "marshal/FlushCommandMarshaller.hpp"

using namespace apache::activemq::client::marshal;

/*
 *  Marshalling code for Open Wire Format for FlushCommand
 *
 * NOTE!: This file is autogenerated - do not modify!
 *        if you need to make a change, please see the Groovy scripts in the
 *        activemq-core module
 */

FlushCommandMarshaller::FlushCommandMarshaller()
{
    // no-op
}

FlushCommandMarshaller::~FlushCommandMarshaller()
{
    // no-op
}



IDataStructure* FlushCommandMarshaller::createObject() 
{
    return new FlushCommand();
}

char FlushCommandMarshaller::getDataStructureType() 
{
    return FlushCommand.ID_FlushCommand;
}

    /* 
     * Un-marshal an object instance from the data input stream
     */ 
void FlushCommandMarshaller::unmarshal(ProtocolFormat& wireFormat, Object o, BinaryReader& dataIn, BooleanStream& bs) 
{
    base.unmarshal(wireFormat, o, dataIn, bs);

}


/*
 * Write the booleans that this object uses to a BooleanStream
 */
int FlushCommandMarshaller::marshal1(ProtocolFormat& wireFormat, Object& o, BooleanStream& bs) {
    FlushCommand& info = (FlushCommand&) o;

    int rc = base.marshal1(wireFormat, info, bs);

    return rc + 0;
}

/* 
 * Write a object instance to data output stream
 */
void FlushCommandMarshaller::marshal2(ProtocolFormat& wireFormat, Object& o, BinaryWriter& dataOut, BooleanStream& bs) {
    base.marshal2(wireFormat, o, dataOut, bs);

}
