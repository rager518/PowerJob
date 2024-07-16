using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Settings.UI.Library.Interfaces;
public interface ISettingsConfig
{
    string ToJsonString();

    string GetModuleName();

    bool UpgradeSettingsConfiguration();
}