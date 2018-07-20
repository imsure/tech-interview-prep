#!/bin/bash

# run pytest without django plugin, otherwise it will load django settings
pytest -p no:django
