/*
 * GdbCrashHandler.hpp
 * Copyright (C) 2017 Sandro Mani <manisandro@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GDBCRASHHANDLER_HPP
#define GDBCRASHHANDLER_HPP

#include <functional>
#include <QIcon>
#include <QString>

namespace GdbCrashHandler {

struct Configuration {
	QString applicationName;
	QString applicationVersion;
	QString applicationIcon;
	enum SubmitMethod {SubmitService} submitMethod;
	QString submitAddress;
};
typedef std::function<QString()> saveCallback_t;

void init(const Configuration& config, saveCallback_t saveCallback = nullptr);

}

#endif // GDBCRASHHANDLER_HPP
