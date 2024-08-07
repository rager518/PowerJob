﻿using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Media;

namespace HostsUILib.Helpers;

public static class VisualTreeUtils
{
    public static T FindVisualChildByType<T>(this DependencyObject element)
        where T : DependencyObject
    {
        if (element == null)
        {
            return null;
        }

        if (element is T elementAsT)
        {
            return elementAsT;
        }

        int childrenCount = VisualTreeHelper.GetChildrenCount(element);
        for (int i = 0; i < childrenCount; i++)
        {
            var result = VisualTreeHelper.GetChild(element, i).FindVisualChildByType<T>();
            if (result != null)
            {
                return result;
            }
        }

        return null;
    }

    public static FrameworkElement FindVisualChildByName(this DependencyObject element, string name)
    {
        if (element == null || string.IsNullOrWhiteSpace(name))
        {
            return null;
        }

        if (element is FrameworkElement elementAsFE && elementAsFE.Name == name)
        {
            return elementAsFE;
        }

        int childrenCount = VisualTreeHelper.GetChildrenCount(element);
        for (int i = 0; i < childrenCount; i++)
        {
            var result = VisualTreeHelper.GetChild(element, i).FindVisualChildByName(name);
            if (result != null)
            {
                return result;
            }
        }

        return null;
    }
}
