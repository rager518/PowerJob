using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Automation.Peers;

namespace PowerJob.Controls;

public class SettingsGroupAutomationPeer : FrameworkElementAutomationPeer
{
    public SettingsGroupAutomationPeer(FrameworkElement owner) : base(owner)
    {
    }
    protected override string GetNameCore()
    {
        var selectedSettingsGroup = (SettingsGroup)Owner;
        return selectedSettingsGroup.Header;
    }

}
