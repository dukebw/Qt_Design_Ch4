#include <QStringList>
#include <QDebug>

/* Some simple examples using QStringList, split and join */

int main()
{
   QString winter{"December, January, February"};   
   QString spring{"March, April, May"};   
   QString summer{"June, July, August"};   
   QString fall{"September, October, November"};   

   QStringList list;
   list << winter;
   list +=spring;
   list.append(summer);
   list << fall;

   qDebug() << "The Spring Months are: " << list[1];

   QString allMonths{list.join(", ")};
   qDebug() << allMonths;

   QStringList list2{allMonths.split(", ")};

   Q_ASSERT(list2.size() == 12);

   foreach(const QString& str, list) {
      qDebug() << QString{" [%1] "}.arg(str);
   }

   for (QStringList::iterator it{list.begin()}; it != list.end(); ++it) {
      QString current{*it};
      qDebug() << "[[" << current << "]]";
   }

   QListIterator<QString> itr{list2};
   while (itr.hasNext()) {
      QString current{itr.next()};
      qDebug() << "{" << current << "}";
   }
}

