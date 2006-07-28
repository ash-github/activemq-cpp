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
 
#ifndef CMS_CLOSEABLE_H
#define CMS_CLOSEABLE_H
 
#include <cms/CMSException.h>

namespace cms{
    
    /**
     * Interface for a class that implements the close method.
     */
    class Closeable{
        
    public:
    
        virtual ~Closeable(void){}
        
        /**
         * Closes this object and deallocates the appropriate resources.
         * The object is generally no longer usable after calling close.
         * @throws CMSException
         */
        virtual void close() throw( CMSException ) = 0;

    };
}

#endif /*CMS_CLOSEABLE_H*/
