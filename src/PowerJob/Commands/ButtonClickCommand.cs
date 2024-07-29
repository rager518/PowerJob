using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace PowerJob.Commands;

public class ButtonClickCommand : ICommand
{
    private readonly Action _execute;

    public ButtonClickCommand(Action execute)
    {
        _execute = execute;
    }

    // Occurs when changes occur that affect whether or not the command should execute.
    public event EventHandler? CanExecuteChanged;

    // Defines the method that determines whether the command can execute in its current state.
    public bool CanExecute(object? parameter)
    {
        return true;
    }

    // Defines the method to be called when the command is invoked.
    public void Execute(object? parameter)
    {
        _execute();
    }

    public void OnCanExecuteChanged() => CanExecuteChanged?.Invoke(this, EventArgs.Empty);
}
