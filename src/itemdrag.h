/*******************************************************************

Part of the Fritzing project - http://fritzing.org
Copyright (c) 2007-2010 Fachhochschule Potsdam - http://fh-potsdam.de

Fritzing is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Fritzing is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Fritzing.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************

$Revision: 5783 $:
$Author: cohen@irascible.com $:
$Date: 2012-01-25 22:31:21 -0800 (Wed, 25 Jan 2012) $

********************************************************************/



#ifndef ITEMDRAG_H
#define ITEMDRAG_H

#include <QDrag>
#include <QHash>
#include <QPixmap>


class ItemDrag : public QObject {
	
Q_OBJECT
	
	
protected:	
	ItemDrag(QObject * parent = 0);
	void __dragIsDone();
	
public:
	static ItemDrag * singleton();
	static QHash<QObject *, QObject *> & cache();
	static void dragIsDone();
	static QWidget * originator();
	static void cleanup();
	static void setOriginator(QWidget *);

signals:
	void dragIsDoneSignal(ItemDrag *);

protected:
	QHash<QObject *, QObject *> m_cache;
	QWidget * m_originator;
	
protected:
	static ItemDrag * Singleton;
};

#endif
