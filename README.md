### This is a python application that uses the OpenAI API to generate text based on a prompt in the terminal.  

### HOW TO USE 
### To run:
```bash
python main.py
```

### To set up:  

After cloning this repo `cd` inside.  

#### 1. Create a virtual environment
```bash
python3 -m venv venv
```

#### 2. Activate the virtual environment
```bash
source ./venv/bin/activate
```

#### 3. Install the required dependencies
```bash
pip install typer
pip install openai
pip install python-dotenv
```

#### 4. Create a `.env` file in the root directory and add a line with the API key
```bash
OPENAI_API_KEY=<your-api-key>
```

#### 5. Run the script
```bash
python main.py
```

#### TO REMOVE THE VIRTUAL ENVIRONMENT
```bash
deactivate

rm -fr venv
```

### SECOND METHOD
macOS

#### Installing Python if not installed:
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

brew install python

# to check if python is installed
python3 --version
pip3 --version
```

#### 1. Setup virtual-env MAC:
```bash
brew install pyenv-virtualenv
```

#### 2. Installing dependencies:
```bash
pip3 install typer openai python-dotenv
```

#### 3. Clone the repository:
```bash
git clone https://github.com/svvoii/chatgpt_clone.git
cd chatgpt_clone
```

#### 4. Installing virtual environment:
```bash
pyenv virtualenv 3.11 chatgpt_clone
```

#### 5. Activating virtual environment:
```bash
pyenv activate chatgpt_clone
```

#### 6. Creating .env file:
```bash
touch .env
```

#### 7. Adding API key to .env file:
```bash
OPENAI_API_KEY=<your-api-key>
```

### To run:
```bash
python main.py
# or python3 main.py
```

#### To deactivate virtual environment:
```bash
source deactivate
```
