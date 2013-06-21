/*
This file is part of Oasis (part of the Bad Camel Gaming toolset).

Oasis is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Oasis is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Oasis.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __OASISMANAGER_H__
#define __OASISMANAGER_H__

#include <OasisCommon.h>
#include <OasisException.h>

namespace Oasis
{
	template <class T>
	class Manager
    {
	public:
		virtual ~Manager(void)
		{
			resetPool();
		}
		
		void resetPool(void)
		{
			m_usedItems.clear();
			m_freeItems.clear();
			OASIS_DELETE_CONTAINER(m_pool);						
		}

		void clearItems(void)
		{		
			for (m_usedItemsIterator = m_usedItems.begin(); m_usedItemsIterator != m_usedItems.end(); m_usedItemsIterator++)
				m_freeItems.push_back(m_usedItemsIterator->second);

			m_usedItems.clear();				
		}

		void setPoolParameters(UInt16 initialSize, UInt16 increaseAmount, UInt16 increaseTrigger)
		{
			m_initialSize = initialSize;
			m_increaseAmount = increaseAmount;
			m_increaseTrigger = increaseTrigger;

			checkPoolSize();
		}

		T *createItem(const String &name)
		{
			if (m_usedItems.find(name) != m_usedItems.end())
				OASIS_EXCEPTION(Exception::ET_DUPLICATE_ITEM, "Manager::createItem", "An item with this name exists");

			checkPoolSize();

			if (m_freeItems.size() == 0)
				increasePoolSize(1);

			Managed *item = m_freeItems.back();
			m_freeItems.pop_back();

			m_usedItems[name] = item;
			
			return static_cast<T*>(item);
		}

		T *getItem(const String &name)
		{
			m_usedItemsIterator = m_usedItems.find(name);

			if (m_usedItemsIterator == m_usedItems.end())
				OASIS_EXCEPTION(Exception::ET_ITEM_NOT_FOUND, "Manager::getItem", "An item with this name could not be found");

			return static_cast<T*>(m_usedItemsIterator->second);
		}

		UInt16 getItemCount(void) const
		{
			return m_usedItems.size();
		}

		T *getFirstItem(void)
		{
			if (m_usedItems.size() == 0)
				return NULL;

			m_usedItemsIterator = m_usedItems.begin();

			return static_cast<T*>(m_usedItemsIterator->second);
		}

		T *getNextItem(void)
		{
			if (getItemCount() == 0)
				return NULL;

			m_usedItemsIterator++;
			if (m_usedItemsIterator == m_usedItems.end())
				return NULL;

			return static_cast<T*>(m_usedItemsIterator->second);	
		}
			
	protected:		
		std::deque<Managed*> m_pool;
		std::deque<Managed*> m_freeItems;

		std::map<String, Managed*> m_usedItems;
		std::map<String, Managed*>::iterator m_usedItemsIterator;

		UInt16 m_initialSize, m_increaseAmount, m_increaseTrigger;

		Manager(void) : m_initialSize(0), m_increaseAmount(0), m_increaseTrigger(0)
		{						
			resetPool();
		}
				
		void checkPoolSize(void)
		{
			if (m_pool.size() < m_initialSize)
				adjustPoolSize(m_initialSize);

			if (m_freeItems.size() < m_increaseTrigger)
				increasePoolSize(m_increaseAmount);
		}

		void increasePoolSize(UInt16 increaseAmount)
		{
			adjustPoolSize(m_pool.size() + increaseAmount);
		}

		void adjustPoolSize(UInt16 finalSize)
		{
			T *item;

			while (m_pool.size() < finalSize)
			{						
				item = new T;

				m_pool.push_back(item);
				m_freeItems.push_back(item);
			}
		}
	};
};

#endif // __OASISMANAGER_H__