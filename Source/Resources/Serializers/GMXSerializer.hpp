/**
 *  @section License
 *
 *      Copyright (C) 2013 Daniel Hrabovcak
 *
 *      This file is a part of the Natural GM IDE.
 *
 *      This program is free software: you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation, either version 3 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/
#pragma once
#ifndef _NGM_GMXSERIALIZER__HPP
#define _NGM_GMXSERIALIZER__HPP
#include "Resources/Serializer.hpp"

namespace NGM
{
	namespace Resource
	{
		struct GMXSerializer : public Serializer
		{
		public:

			//void read(Widget *widget, Resource *resource);

			//void write(Widget *widget, Resource *resource);

			void structure(Model::ResourceItem *item);

		};
	}
}

#endif // _NGM_GMXSERIALIZER__HPP