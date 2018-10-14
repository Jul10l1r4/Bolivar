#!/bin/bash

chmod +x run.sh
./run.sh
if [ $? != 0 ]; then
				echo "HOUVE UM ERRO"
				exit 1
else
				echo "Funcionamento ok"
				exit 0
fi
