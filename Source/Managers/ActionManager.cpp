/**
 *  @file ActionManager.cpp
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
#include <QFile>
#include "ActionManager.hpp"
#include "WindowManager.hpp"
#include "ProjectManager.hpp"
#include "../Resources/Project.hpp"
#include <QDebug>

namespace NGM
{
	namespace Manager
	{
		ActionManager::ActionManager(WindowManager *manager, ProjectManager *project) :
			theme("icons/Silk Icons"), project(project), manager(manager)
			/*dragdrop
			(
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
			)*/
		{
			// None. Load only when requested.
		}

		ActionManager::~ActionManager()
		{
			unloadDragDrop();
		}

		QIcon *ActionManager::getIconFromTheme(const QString &location) const
		{
			return iconByTheme.find(location)->second;
		}

		QIcon *ActionManager::getIconFromFile(const QString &location) const
		{
			return iconByTheme.find(location)->second;
		}

		void ActionManager::reload()
		{
			if (QFile::exists(theme+"/main/newproject.png"))
			{
				actions[ActionNewProject]->setIcon(QIcon(theme+"/main/newproject.png"));
			}
			if (QFile::exists(theme+"/main/openproject.png"))
			{
				actions[ActionOpenProject]->setIcon(QIcon(theme+"/main/openproject.png"));
			}
			if (QFile::exists(theme+"/main/save.png"))
			{
				actions[ActionSave]->setIcon(QIcon(theme+"/main/save.png"));
			}
			if (QFile::exists(theme+"/main/saveall.png"))
			{
				actions[ActionSaveAll]->setIcon(QIcon(theme+"/main/saveall.png"));
			}
			if (QFile::exists(theme+"/main/cut.png"))
			{
				actions[ActionCut]->setIcon(QIcon(theme+"/main/cut.png"));
			}
			if (QFile::exists(theme+"/main/copy.png"))
			{
				actions[ActionCopy]->setIcon(QIcon(theme+"/main/copy.png"));
			}
			if (QFile::exists(theme+"/main/paste.png"))
			{
				actions[ActionPaste]->setIcon(QIcon(theme+"/main/paste.png"));
			}
			if (QFile::exists(theme+"/main/redo.png"))
			{
				actions[ActionRedo]->setIcon(QIcon(theme+"/main/redo.png"));
			}
			if (QFile::exists(theme+"/main/undo.png"))
			{
				actions[ActionUndo]->setIcon(QIcon(theme+"/main/undo.png"));
			}
			for(auto& i : project->types)
			{
				//i.second->icon = QIcon(theme+"/project/"+i.first);
			}
		}

		void ActionManager::unload()
		{
			actions[ActionNewProject]->setIcon(QIcon());
			actions[ActionOpenProject]->setIcon(QIcon());
			actions[ActionSave]->setIcon(QIcon());
			actions[ActionCut]->setIcon(QIcon());
			actions[ActionCopy]->setIcon(QIcon());
			actions[ActionPaste]->setIcon(QIcon());
			actions[ActionUndo]->setIcon(QIcon());
			actions[ActionRedo]->setIcon(QIcon());
		}

		void ActionManager::reloadDragDrop()
		{
			unloadDragDrop();
			if (QFile::exists(theme+"/dragdrop/actionif.png"))
			{
				icons[DNDIf] = new QIcon(theme+"/dragdrop/actionif.png");
			}
		}

		void ActionManager::unloadDragDrop()
		{
			for (size_t i = 0; i < 192; ++i)
			{
				delete dragdrop[i];
			}
		}

		void ActionManager::reloadAll()
		{
			unload();
			reload();
			unloadDragDrop();
			reloadDragDrop();
		}

		void ActionManager::setTheme(const QString &_theme)
		{
			theme = _theme;
		}

		const QString ActionManager::getTheme() const
		{
			return theme;
		}
	}
}