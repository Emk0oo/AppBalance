# Application Balance serie

Cette application permet de récupérer le poids d'un ensemble d'articles pesés sur une balance (PCE-BSH-1000), par un préparateur d'un drive, en liaison série. Le poids est retourné vers un autre poste informatique pour traitement. 

Le programme est rédigé en C++ sur Qt Creator 4.11.0 sous Ubuntu 20.04.5 LTS.


## Installation

Il est fortement conseillé de suivre ce tuto [tuto](https://unix.stackexchange.com/questions/14354/read-write-to-a-serial-port-without-root) pour obtenir les droits de lecture/écriture sans root. 



```bash
usermod -a -G dialout $USER
```



## Contributing

Les pull requests sont les bienvenues. Pour les modifications majeures, veuillez d'abord ouvrir un problème
pour discuter de ce que vous aimeriez changer.

Assurez-vous de mettre à jour les tests, le cas échéant.

## License

[MIT](https://choosealicense.com/licenses/mit/)
