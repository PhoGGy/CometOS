/*
 * CometOS --- a component-based, extensible, tiny operating system
 *             for wireless networks
 *
 * Copyright (c) 2015, Institute of Telematics, Hamburg University of Technology
 * All rights reserved.

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/**
 * @author Andreas Weigel
 *  Created on: 19.04.2012
 */

#ifndef PRECFGADDRESSING_H_
#define PRECFGADDRESSING_H_

#include "MacAddressingBase.h"

namespace cometos {

#ifndef COMETOS_MAC_SHORT_ADDR
#	define COMETOS_MAC_SHORT_ADDR 1
#endif

#ifndef COMETOS_MAC_NWK_ID
#   define COMETOS_MAC_NWK_ID 1
#endif

/**
 * Simple addressing module for a hardware platform,
 * configurable at compile time via -DMAC_SHORT_ADDRESS
 * and -DMAC_NWK_ID command line parameters. Uses the
 * module ID as node ID and
 */
class MacCompileAddressing : public MacAddressingBase {
public:
	MacCompileAddressing(const char * service_name = NULL);

	virtual void initialize();

	/**
	 * @inheritDoc
	 */
	virtual node_t getShortAddr() const;

	/**
	 * @inheritDoc
	 */
	virtual bool setShortAddr(node_t newAddr);

private:
	node_t id;
};

} // namespace

#endif /* PRECFGADDRESSING_H_ */
