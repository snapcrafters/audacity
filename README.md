<h1 align="center">
  <img src="snap-assets/logo.png" alt="Audacity">
  <br />
  Audacity
</h1>

<p align="center"><b>This is the snap for Audacity</b>, <i>“Audio software for multi-track recording and editing”</i>. It works on Ubuntu, Fedora, Debian, and other major Linux
distributions.</p>

<p align="center">
<a href="https://snapcraft.io/audacity"><img src="https://snapcraft.io/audacity/badge.svg" alt="Snap Status"></a>
<a href="https://github.com/snapcrafters/audacity/actions/workflows/sync-version-with-upstream.yml"><img src="https://github.com/snapcrafters/audacity/actions/workflows/sync-version-with-upstream.yml/badge.svg"></a>
<a href="https://github.com/snapcrafters/audacity/actions/workflows/release-to-candidate.yml"><img src="https://github.com/snapcrafters/audacity/actions/workflows/release-to-candidate.yml/badge.svg"></a>
<a href="https://github.com/snapcrafters/audacity/actions/workflows/promote-to-stable.yml"><img src="https://github.com/snapcrafters/audacity/actions/workflows/promote-to-stable.yml/badge.svg"></a>
</p>


## Install

    sudo snap install audacity

([Don't have snapd installed?](https://snapcraft.io/docs/core/install))

<p align="center">Published for <img src="https://raw.githubusercontent.com/anythingcodes/slack-emoji-for-techies/gh-pages/emoji/tux.png" align="top" width="24" /> with :gift_heart: by Snapcrafters</p>

## Audacity 3

To install the Audacity 3 track, use `sudo snap install audacity --channel=3/stable`.
See the [Audacity 3 branch](https://github.com/snapcrafters/audacity/tree/3#openvino-ai-plugins) for OpenVINO plugin instructions.

## How to contribute to this snap

Thanks for your interest! Below you find instructions to help you contribute to this snap.

Target the `candidate` branch for the default track or the `3` branch for Audacity 3 maintenance. Merges publish to `latest/candidate` or `3/candidate`, respectively. After testing, maintainers promote the tested revisions to `latest/stable` or `3/stable` from the corresponding call-for-testing issue.

### Initial setup

If this is your first time contributing to this snap, you first need to set up your own fork of this repository.

1. [Fork the repository](https://docs.github.com/en/github/getting-started-with-github/fork-a-repo) into your own GitHub namespace.
2. [Clone your fork](https://git-scm.com/book/en/v2/Git-Basics-Getting-a-Git-Repository), so that you have it on your local computer.
3. Configure your local repo. To make things a bit more intuitive, we will rename your fork's remote to `myfork`, and add the snapcrafters repo as `snapcrafters`.

    ```shell
    git remote rename origin myfork
    git remote add snapcrafters https://github.com/snapcrafters/audacity.git
    git fetch --all
    ```

### Submitting changes in a pull request

Once you're all setup for contributing, keep in mind that you want the git information to be all up-to-date. So if you haven't "fetched" all changes in a while, start with that:

```shell
git fetch --all -p
```

Now that your git metadata has been updated you are ready to create a bugfix branch, make your changes, and open a pull request.

1. Start from the branch for the track you are changing (this example uses `candidate`):

    ```shell
    git checkout -b my-bugfix-branch snapcrafters/candidate
    ```

2. Make your desired changes and build a snap locally for testing:

    ```shell
    snapcraft --use-lxd
    ```

3. After you are happy with your changes, commit them and push them to your fork so they are available on GitHub:

    ```shell
    git commit -a
    git push -u myfork my-bugfix-branch
    ```

4. [Open a pull request](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/about-pull-requests) against the same branch you started from: `candidate` or `3`.
5. Once you've opened the pull request, it will automatically trigger the build-test action that will launch a build of the snap. You can watch the progress of the snap build from your pull request (Show all checks -> Details). Once the snap build has completed, you can find the built snap (to test with) under "Artifacts".
6. Someone from the team will review the open pull request and either merge it or start a discussion with you with additional changes or clarification needed.

## Maintainers

-   [@lucyllewy](https://github.com/lucyllewy/)

## License

-   The license of the build files in this repository is [MIT](https://github.com/snapcrafters/audacity/blob/candidate/LICENSE)
