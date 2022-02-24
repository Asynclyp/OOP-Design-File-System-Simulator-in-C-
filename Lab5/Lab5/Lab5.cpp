// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\AbstractFileSystem.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\MetadataDisplayVisitor.h"
#include "..\..\\SharedCode\BasicDisplayVisitor.h"
#include "..\..\\SharedCode\PasswordProxy.h"
#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\CommandPrompt.h"
#include "..\..\\SharedCode\TouchCommand.h"
#include "..\..\\SharedCode\LSCommand.h"
#include "..\..\\SharedCode\RemoveCommand.h"
#include "..\..\\SharedCode\CatCommand.h"
#include "..\..\\SharedCode\DisplayCommand.h"
#include "..\..\\SharedCode\CopyCommand.h"
#include "..\..\\SharedCode\MacroCommand.h"
#include "..\..\\SharedCode\RenameParsingStrategy.h"
#include "..\..\\SharedCode\QuickCreateParsingStrategy.h"
#include <iostream>
#include <memory>
using namespace std;

int main()
{
	shared_ptr<AbstractFileSystem> afs(new SimpleFileSystem());
	shared_ptr<AbstractFileFactory> aff(new SimpleFileFactory());
	auto sfs = afs.get();
	auto sff = aff.get();

	shared_ptr<CommandPrompt> cp(new CommandPrompt());

	cp->setFileSystem(sfs);
	cp->setFileFactory(sff);

	// Add commands
	shared_ptr<AbstractCommand> touch_command (new TouchCommand(sfs,sff));
	string commandname = "touch";
	cp->addCommand(commandname, touch_command.get());

	shared_ptr<AbstractCommand> ls_command(new LSCommand(sfs));
	commandname = "ls";
	cp->addCommand(commandname, ls_command.get());

	shared_ptr<AbstractCommand> remove_command(new RemoveCommand(sfs));
	commandname = "rm";
	cp->addCommand(commandname, remove_command.get());

	shared_ptr<AbstractCommand> cat_command(new CatCommand(sfs));
	commandname = "cat";
	cp->addCommand(commandname, cat_command.get());

	shared_ptr<AbstractCommand> ds_command(new DisplayCommand(sfs));
	commandname = "ds";
	cp->addCommand(commandname, ds_command.get());

	shared_ptr<AbstractCommand> copy_command(new CopyCommand(sfs));
	commandname = "cp";
	cp->addCommand(commandname, copy_command.get());

	// Macro Commands
	shared_ptr<MacroCommand> macro(new MacroCommand(sfs));

	//command = new CopyCommand(sfs);
	macro->addCommand(copy_command.get());
	//command = new RemoveCommand(sfs);
	macro->addCommand(remove_command.get());

	shared_ptr<AbstractParsingStrategy> strategy(new RenameParsingStrategy());
	macro->setParseStrategy(strategy.get());
	commandname = "rn";
	cp->addCommand(commandname, macro.get());

	shared_ptr<MacroCommand> another_macro(new MacroCommand(sfs));
	another_macro->addCommand(touch_command.get());
	another_macro->addCommand(cat_command.get());
	
	shared_ptr<AbstractParsingStrategy> strategy_two(new QuickCreateParsingStrategy());
	another_macro->setParseStrategy(strategy_two.get());
	commandname = "qc";
	cp->addCommand(commandname, another_macro.get());

	// Run command prompt
	while (cp->run() != ReturnType::quit) {}

	return 0;//done
}


