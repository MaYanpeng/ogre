/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2008 Renato Araujo Oliveira Filho <renatox@gmail.com>
Copyright (c) 2000-2009 Torus Knot Software Ltd

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/

#ifndef __OgreGLESContext_H__
#define __OgreGLESContext_H__

#include "OgreGLESPrerequisites.h"

namespace Ogre {
    /**
     * Class that encapsulates an GL context. (IE a window/pbuffer). This is a 
     * virtual base class which should be implemented in a GLSupport.
     * This object can also be used to cache renderstate if we decide to do so
     * in the future.
     */
    class _OgreGLESExport GLESContext
    {
        public:
            GLESContext();
            virtual ~GLESContext();

            /**
             * Enable the context. All subsequent rendering commands will go here.
             */
            virtual void setCurrent() = 0;

            /**
             * This is called before another context is made current. By default,
             * nothing is done here.
             */
            virtual void endCurrent() = 0;

            bool getInitialized() { return initialized; };
            void setInitialized() { initialized = true; };

            /** Create a new context based on the same window/pbuffer as this
                context - mostly useful for additional threads.
            @note The caller is responsible for deleting the returned context.
            */
            virtual GLESContext* clone() const = 0;

        protected:
            bool initialized;
    };
}

#endif
