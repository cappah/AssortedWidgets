#include "SelectionManager.h"
#include "ContainerElement.h"

namespace AssortedWidgets
{
	namespace Manager
	{
		SelectionManager::~SelectionManager(void)
		{
			//clear();
		}

		void SelectionManager::registerComponent(Widgets::Component *component)
		{
            int hSIndex(static_cast<int>(static_cast<float>(component->m_position.x)/static_cast<float>(m_gridSize)));
            int vSIndex(static_cast<int>(static_cast<float>(component->m_position.y)/static_cast<float>(m_gridSize)));
            int hEIndex(static_cast<int>(static_cast<float>(component->m_position.x+component->m_size.m_width)/static_cast<float>(m_gridSize)));
            int vEIndex(static_cast<int>(static_cast<float>(component->m_position.y+component->m_size.m_height)/static_cast<float>(m_gridSize)));
			hSIndex=std::max<int>(hSIndex,0);
			vSIndex=std::max<int>(vSIndex,0);
            hEIndex=std::min<int>(hEIndex,m_horizonalCount-1);
            vEIndex=std::min<int>(vEIndex,m_verticalCount-1);

			for(int i=hSIndex;i<=hEIndex;++i)
			{
				for(int e=vSIndex;e<=vEIndex;++e)
				{
                    m_gridTable[i][e].push_back(component);
				}
			}
		}

		void SelectionManager::changePosition(Util::Position &oldP,Util::Size &oldS,Widgets::Component *component)
		{
            int ohSIndex(static_cast<int>(static_cast<float>(oldP.x)/static_cast<float>(m_gridSize)));
            int ovSIndex(static_cast<int>(static_cast<float>(oldP.y)/static_cast<float>(m_gridSize)));
            int ohEIndex(static_cast<int>(static_cast<float>(oldP.x+oldS.m_width)/static_cast<float>(m_gridSize)));
            int ovEIndex(static_cast<int>(static_cast<float>(oldP.y+oldS.m_height)/static_cast<float>(m_gridSize)));
			ohSIndex=std::max<int>(ohSIndex,0);
			ovSIndex=std::max<int>(ovSIndex,0);
            ohEIndex=std::min<int>(ohEIndex,m_horizonalCount-1);
            ovEIndex=std::min<int>(ovEIndex,m_verticalCount-1);

			for(int i=ohSIndex;i<=ohEIndex;++i)
			{
				for(int e=ovSIndex;e<=ovEIndex;++e)
				{
                    m_gridTable[i][e].erase(std::remove(m_gridTable[i][e].begin(),m_gridTable[i][e].end(),component),m_gridTable[i][e].end());
				}
			}

            int hSIndex(static_cast<int>(static_cast<float>(component->m_position.x)/static_cast<float>(m_gridSize)));
            int vSIndex(static_cast<int>(static_cast<float>(component->m_position.y)/static_cast<float>(m_gridSize)));
            int hEIndex(static_cast<int>(static_cast<float>(component->m_position.x+component->m_size.m_width)/static_cast<float>(m_gridSize)));
            int vEIndex(static_cast<int>(static_cast<float>(component->m_position.y+component->m_size.m_height)/static_cast<float>(m_gridSize)));
			hSIndex=std::max<int>(hSIndex,0);
			vSIndex=std::max<int>(vSIndex,0);
            hEIndex=std::min<int>(hEIndex,m_horizonalCount-1);
            vEIndex=std::min<int>(vEIndex,m_verticalCount-1);

			for(int i=hSIndex;i<=hEIndex;++i)
			{
				for(int e=vSIndex;e<=vEIndex;++e)
				{
                    m_gridTable[i][e].push_back(component);
				}
			}
		}
	}
}
