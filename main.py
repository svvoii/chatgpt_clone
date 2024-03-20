import os # for environment variables and API keys security
import typer # for command line interface (print, input, etc.)
from typing import Optional
from openai import OpenAI
from dotenv import load_dotenv # for loading environment variables from .env file

# load environment variables from .env file
load_dotenv()

client = OpenAI(api_key=os.getenv("OPENAI_API_KEY")) # for GPT-3 / GPT-4 API

# create a new Typer app instance
app = typer.Typer()

@app.command()
def interactive_chat(
	test: Optional[str] = typer.Option(None, "--text", "-t", help="Start with text to chat with the model."),
	temperature: float = typer.Option(0.7, help="Controls Randomness: Lower value means more predictable text.."),
	max_tokens: int = typer.Option(
		50, help="Controls the length of the response."
	),
	model: str = typer.Option(
		"gpt-3.5-turbo", help="The model to use for generating the response."
	),
):

	""" Interactive CLI chat with Chat GPT via API """
	typer.echo(
		"Welcome to the interactive chat with Chat GPT! Type 'exit' to end the chat."
	)

	messages = []

	# start the chat loop
	while True:
		# get user input
		prompt = input("You: ")
		messages.append({"role": "user", "content": prompt})

		if prompt.lower() == "exit":
			typer.echo("Goodbye!")
			break

		response = client.chat.completions.create(
			model=model,
			messages=messages,
			temperature=temperature,
			max_tokens=max_tokens,
		)

		# print the chatbot response
		typer.echo(f'ChatGPT: {response.choices[0].message.content}')
		messages.append({"role": "assistant", "content": response.choices[0].message.content})

if __name__ == "__main__":
	app()
