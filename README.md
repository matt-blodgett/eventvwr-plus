# eventvwr-plus

This is a fun project in which I try to create different GUI programs that emulate real, native Windows 10 apps.
The inspiration came from Twitch.tv streamer [Kitboga](https://www.twitch.tv/kitboga), who is known for calling phone scammers and wasting their time.
They will often gain access to his computer where they will find a host of fake programs designed to mess with them, most notably a fake bank account webpage.

## Run

[Run](./eventvwr-plus/run) is a fake Windows run box (opened with `⊞ Win` + `R`)

It is often used by scammers to access webpages or open `eventvwr` to show an unfamiliar user all of the "errors" they have on their computer.

This run box maps commands to be re-routed to different commands.
Using a `commands.json` file, you can map commands like so:
```json
{
  "calc": "mspaint",
  "mspaint": "calc"
}
```

The configuration would be read and the commands re-directed. This configuration would switch the `calc` command (for bringing up the calculator) with the `mspaint` command (for opening paint)

In the future, it will support `*` matching.

It could be used to trick scammers or maybe for pranks!

![Side by side example](./screen.png)
