using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Principal;
using System.Text;
using System.Threading.Tasks;

namespace HostsUILib.Helpers;
public class ElevationHelper : IElevationHelper
{
    private readonly bool _isElevated;

    public bool IsElevated => _isElevated;

    public ElevationHelper()
    {
        _isElevated = new WindowsPrincipal(WindowsIdentity.GetCurrent()).IsInRole(WindowsBuiltInRole.Administrator);
    }
}